//
// Created by waschbar on 12.01.22.
//

#include "YamlSerializer.h"

YAML::Node YamlSerializer::serialize(const std::vector<stt::StrongType>& strongTypes) {
    YAML::Node node;
    for(const stt::StrongType& type : strongTypes) {
        node["StrongTypes"].push_back(serializeStrongType(type));
    }
    return node;
}

YAML::Node YamlSerializer::serializeStrongType(const stt::StrongType& strongType) {
    YAML::Node node;
    node["TypeName"] = strongType.getTypeName();
    node["Wraps"] = strongType.getWraps();

    for(const stt::BinaryOperation& op : strongType.getBinaryOperations()) {
        node["BinaryOperations"].push_back(serializeBinaryOperation(op));
    }
    for(const stt::UnaryOperation& op : strongType.getUnaryOperations()) {
        node["UnaryOperations"].push_back(serializeUnaryOperation(op));
    }

    return node;
}

YAML::Node YamlSerializer::serializeBinaryOperation(const stt::BinaryOperation& binaryOperation) {
    YAML::Node node;
    node["Operation"] = binaryOperation.getOperation();
    node["ArgType"] = binaryOperation.getArgType();
    node["ResType"] = binaryOperation.getResType();
    return node;
}

YAML::Node YamlSerializer::serializeUnaryOperation(const stt::UnaryOperation& unaryOperation) {
    YAML::Node node;
    node["Operation"] = unaryOperation.getOperation();
    node["ResType"] = unaryOperation.getResType();
    return node;
}
