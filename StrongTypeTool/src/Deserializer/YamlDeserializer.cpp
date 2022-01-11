//
// Created by waschbar on 11.01.22.
//

#include "YamlDeserializer.h"

std::vector<stt::StrongType> YamlDeserializer::deserialize(std::string filePath) {
    YAML::Node config = YAML::LoadFile(filePath);
    std::vector<stt::StrongType> types{};
    for(int i = 0; i < config["StrongTypes"].size(); i++) {
        types.push_back(deserializeStrongType(config["StrongTypes"][i]));
    }
    return types;
}

stt::StrongType YamlDeserializer::deserializeStrongType(YAML::Node node) {
    std::vector<stt::BinaryOperation> binOps{};
    for(int i = 0; i < node["BinaryOperations"].size(); i++) {
        binOps.push_back(deserializeBinaryOperation(node["BinaryOperations"][i]));
    }
    return {node["TypeName"].as<std::string>(),
            node["Wraps"].as<std::string>(),
            binOps
            };
}

stt::BinaryOperation YamlDeserializer::deserializeBinaryOperation(YAML::Node node) {
    return {node["Operation"].as<std::string>(),
            node["ArgType"].as<std::string>(),
            node["ResType"].as<std::string>()
           };
}
