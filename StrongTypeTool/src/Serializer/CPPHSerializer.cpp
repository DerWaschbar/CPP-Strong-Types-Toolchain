//
// Created by waschbar on 24.01.22.
//

#include "CPPHSerializer.h"

#include <nlohmann/json.hpp>
#include <inja/inja.hpp>
#include <boost/algorithm/string.hpp>

std::vector<std::string> CPPHSerializer::serialize(const stt::StrongTypeSet& strongTypeSet) {
    std::vector<std::string> headers(strongTypeSet.getTypes().size());
    for(const stt::StrongType& type : strongTypeSet.getTypes()) {
        headers.push_back(serializeStrongType(type));
    }
    return headers;
}

std::string CPPHSerializer::serializeStrongType(const stt::StrongType &strongType) {
    std::string ops;
    for(const stt::BinaryOperation &op : strongType.getBinaryOperations()) {
        ops += serializeBinaryOperation(op);
    }

    if(!strongType.getBinaryOperations().empty() && !strongType.getUnaryOperations().empty())
        ops += "\n";

    for(const stt::UnaryOperation &op : strongType.getUnaryOperations()) {
        ops += serializeUnaryOperation(op);
    }


    nlohmann::json type;
    type["name"] = strongType.getTypeName();
    type["NAME"] = boost::to_upper_copy<std::string>(strongType.getTypeName());
    type["wraps"] = strongType.getWraps();
    type["ops"] = ops;

    return inja::render((&templateManager)->getTemplate(Template::T_ClassHeader), type);
}

std::string CPPHSerializer::serializeBinaryOperation(const stt::BinaryOperation &binaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = binaryOperation.getResType();
    opJson["arg"] = binaryOperation.getArgType();
    opJson["op"] = binaryOperation.getOperation();

    Template aTemplate = binaryOperation.isBinaryAssignment() ? Template::T_BinaryAssignmentOpHeader : Template::T_BinaryOpHeader;

    return inja::render((&templateManager)->getTemplate(aTemplate), opJson);
}

std::string CPPHSerializer::serializeUnaryOperation(const stt::UnaryOperation &unaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = unaryOperation.getResType();
    opJson["op"] = unaryOperation.getOperation();

    return inja::render((&templateManager)->getTemplate(Template::T_UnaryOpHeader), opJson);
}
