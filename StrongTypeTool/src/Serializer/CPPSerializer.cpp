//
// Created by waschbar on 26.01.22.
//

#include "CPPSerializer.h"

#include <nlohmann/json.hpp>
#include <inja/inja.hpp>
#include <boost/algorithm/string.hpp>

std::vector<std::string> CPPSerializer::serialize(const std::vector<stt::StrongType> &strongTypes) {
    std::vector<std::string> classes(strongTypes.size());
    for(const stt::StrongType& type : strongTypes) {
        classes.push_back(serializeStrongType(type));
    }
    return classes;
}

std::string CPPSerializer::serializeStrongType(const stt::StrongType &strongType) {
    nlohmann::json type;
    type["name"] = strongType.getTypeName();
    type["NAME"] = boost::to_upper_copy<std::string>(strongType.getTypeName());
    type["wraps"] = strongType.getWraps();

    std::string ops;
    for(const stt::BinaryOperation &op : strongType.getBinaryOperations()) {
        ops += inja::render(serializeBinaryOperation(op), type);
    }

    for(const stt::UnaryOperation &op : strongType.getUnaryOperations()) {
        ops += inja::render(serializeUnaryOperation(op), type);
    }

    type["ops"] = ops;

    return inja::render((&templateManager)->getTemplate(Template::T_Class), type);
}

std::string CPPSerializer::serializeBinaryOperation(const stt::BinaryOperation &binaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = binaryOperation.getResType();
    opJson["arg"] = binaryOperation.getArgType();
    opJson["op"] = binaryOperation.getOperation();
    opJson["name"] = "{{ name }}";

    Template aTemplate = binaryOperation.isBinaryAssignment() ? Template::T_BinaryAssignmentOp : Template::T_BinaryOp;

    return inja::render((&templateManager)->getTemplate(aTemplate), opJson);
}

std::string CPPSerializer::serializeUnaryOperation(const stt::UnaryOperation &unaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = unaryOperation.getResType();
    opJson["op"] = unaryOperation.getOperation();
    opJson["name"] = "{{ name }}";

    return inja::render((&templateManager)->getTemplate(Template::T_UnaryOp), opJson);
}
