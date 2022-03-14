//
// Created by waschbar on 28.02.22.
//

#include "HeaderOnlySerializer.h"

#include <nlohmann/json.hpp>
#include <inja/inja.hpp>
#include <boost/algorithm/string.hpp>


std::vector<std::string> HeaderOnlySerializer::serialize(const stt::StrongTypeSet &strongTypeSet) {
    std::vector<std::string> classes;
    for(const stt::StrongType& type : strongTypeSet.getTypes()) {
        classes.push_back(serializeStrongType(type, strongTypeSet.getDependencies(type)));
    }
    return classes;
}

std::string HeaderOnlySerializer::serializeStrongType(const stt::StrongType &strongType, const std::vector<stt::StrongType> &includedTypes) {
    nlohmann::json type;
    type["name"] = strongType.getTypeName();
    type["NAME"] = boost::to_upper_copy<std::string>(strongType.getTypeName());
    type["wraps"] = strongType.getWraps();
    type["includes"] = serializeIncludes(includedTypes);

    std::string ops;
    std::string opDefinitions;
    for(const stt::BinaryOperation &op : strongType.getBinaryOperations()) {
        std::pair<std::string, std::string> res = serializeBinaryOperation(op);
        ops += "\tinline " + inja::render(res.first, type);
        opDefinitions += inja::render(res.second, type);
    }

    if(!strongType.getBinaryOperations().empty() && !strongType.getUnaryOperations().empty())
        ops += "\n";

    for(const stt::UnaryOperation &op : strongType.getUnaryOperations()) {
        std::pair<std::string, std::string> res = serializeUnaryOperation(op);
        ops += "\tinline " + inja::render(res.first, type);
        opDefinitions += inja::render(res.second, type);
    }

    type["ops"] = ops;
    type["op_definitions"] = opDefinitions;

    return inja::render((&templateManager)->getTemplate(Template::T_ClassHeaderOnly), type);
}

std::pair<std::string, std::string> HeaderOnlySerializer::serializeBinaryOperation(const stt::BinaryOperation &binaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = binaryOperation.getResType();
    opJson["arg"] = binaryOperation.getArgType();
    opJson["op"] = binaryOperation.getOperation();
    opJson["name"] = "{{ name }}";

    Template defTemplate = binaryOperation.isBinaryAssignment() ? Template::T_BinaryAssignmentOp : Template::T_BinaryOp;
    Template headerTemplate = binaryOperation.isBinaryAssignment() ? Template::T_BinaryAssignmentOpHeader : Template::T_BinaryOpHeader;

    return {
        inja::render((&templateManager)->getTemplate(headerTemplate), opJson),
        inja::render((&templateManager)->getTemplate(defTemplate), opJson)
    };
}

std::pair<std::string, std::string> HeaderOnlySerializer::serializeUnaryOperation(const stt::UnaryOperation &unaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = unaryOperation.getResType();
    opJson["op"] = unaryOperation.getOperation();
    opJson["name"] = "{{ name }}";

    return {
            inja::render((&templateManager)->getTemplate(Template::T_UnaryOpHeader), opJson),
            inja::render((&templateManager)->getTemplate(Template::T_UnaryOp), opJson)
    };
}

std::string HeaderOnlySerializer::serializeIncludes(const std::vector<stt::StrongType>& includedTypes) {
    std::string includes;

    nlohmann::json includeData;
    for(const stt::StrongType &type : includedTypes) {
        includeData["include_path"] = type.getTypeName() + ".h";
        includes += inja::render((&templateManager)->getTemplate(Template::T_Include), includeData);
    }
    return includes;
}