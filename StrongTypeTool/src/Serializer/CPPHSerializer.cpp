//
// Created by Beka Grdzelishvili (DerWaschbar) on 24.01.22.
//

#include "CPPHSerializer.h"

#include <boost/algorithm/string.hpp>
#include <inja/inja.hpp>
#include <nlohmann/json.hpp>

std::vector<std::string> CPPHSerializer::serialize(const stt::StrongTypeSet& strongTypeSet) {
    std::vector<std::string> headers;
    for(const stt::StrongType& type : strongTypeSet.getTypes()) {
        headers.push_back(serializeStrongType(type, strongTypeSet.getDependencies(type)));
    }
    return headers;
}

std::string CPPHSerializer::serializeStrongType(const stt::StrongType& strongType,
                                                const std::vector<stt::StrongType>& includedTypes) {
    std::string ops;
    for(const stt::BinaryOperation& op : strongType.getBinaryOperations()) {
        ops += "\t" + serializeBinaryOperation(op);
    }

    if(!strongType.getBinaryOperations().empty() && !strongType.getUnaryOperations().empty())
        ops += "\n";

    for(const stt::UnaryOperation& op : strongType.getUnaryOperations()) {
        ops += "\t" + serializeUnaryOperation(op);
    }


    nlohmann::json type;
    type["name"] = strongType.getTypeName();
    type["NAME"] = boost::to_upper_copy<std::string>(strongType.getTypeName());
    type["wraps"] = strongType.getWraps();
    type["ops"] = ops;
    type["includes"] = serializeIncludes(includedTypes);

    return inja::render((&templateManager)->getTemplate(Template::T_ClassHeader), type);
}

std::string CPPHSerializer::serializeBinaryOperation(const stt::BinaryOperation& binaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = binaryOperation.getResType();
    opJson["arg"] = binaryOperation.getArgType();
    opJson["op"] = binaryOperation.getOperation();

    Template aTemplate = binaryOperation.isBinaryAssignment() ? Template::T_BinaryAssignmentOpHeader
                                                              : Template::T_BinaryOpHeader;

    return inja::render((&templateManager)->getTemplate(aTemplate), opJson);
}

std::string CPPHSerializer::serializeUnaryOperation(const stt::UnaryOperation& unaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = unaryOperation.getResType();
    opJson["op"] = unaryOperation.getOperation();

    return inja::render((&templateManager)->getTemplate(Template::T_UnaryOpHeader), opJson);
}

std::string CPPHSerializer::serializeIncludes(const std::vector<stt::StrongType>& includedTypes) {
    std::string includes;

    nlohmann::json includeData;
    for(const stt::StrongType& type : includedTypes) {
        includeData["include_path"] = type.getTypeName() + ".h";
        includes += inja::render((&templateManager)->getTemplate(Template::T_Include), includeData);
    }
    return includes;
}
