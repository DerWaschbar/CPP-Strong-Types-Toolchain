//
// Created by Beka Grdzelishvili (DerWaschbar) on 26.01.22.
//

#include "CPPSerializer.h"

#include <boost/algorithm/string.hpp>
#include <inja/inja.hpp>
#include <nlohmann/json.hpp>

std::vector<std::string> CPPSerializer::serialize(const stt::StrongTypeSet& strongTypeSet) {
    std::vector<std::string> classes;
    for(const stt::StrongType& type : strongTypeSet.getTypes()) {
        classes.push_back(serializeStrongType(type));
    }
    return classes;
}

std::string CPPSerializer::serializeStrongType(const stt::StrongType& strongType) {
    nlohmann::json type;
    type["name"] = strongType.getTypeName();
    type["NAME"] = boost::to_upper_copy<std::string>(strongType.getTypeName());
    type["wraps"] = strongType.getWraps();

    std::string ops;
    for(const stt::BinaryOperation& op : strongType.getBinaryOperations()) {
        ops += inja::render(serializeBinaryOperation(op), type);
    }

    for(const stt::UnaryOperation& op : strongType.getUnaryOperations()) {
        ops += inja::render(serializeUnaryOperation(op), type);
    }

    type["ops"] = ops;

    return inja::render((&templateManager)->getTemplate(Template::T_Class), type);
}

std::string CPPSerializer::serializeBinaryOperation(const stt::BinaryOperation& binaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = binaryOperation.getResType();
    opJson["arg"] = binaryOperation.getArgType();
    opJson["op"] = binaryOperation.getOperation();
    opJson["name"] = "{{ name }}";

    Template aTemplate = binaryOperation.isBinaryAssignment() ? Template::T_BinaryAssignmentOp
                                                              : Template::T_BinaryOp;

    return inja::render((&templateManager)->getTemplate(aTemplate), opJson);
}

std::string CPPSerializer::serializeUnaryOperation(const stt::UnaryOperation& unaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = unaryOperation.getResType();
    opJson["op"] = unaryOperation.getOperation();
    opJson["name"] = "{{ name }}";

    return inja::render((&templateManager)->getTemplate(Template::T_UnaryOp), opJson);
}
