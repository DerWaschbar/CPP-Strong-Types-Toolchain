//
// Created by Beka Grdzelishvili (DerWaschbar) on 11.01.22.
//

#include "YamlDeserializer.h"

stt::StrongTypeSet YamlDeserializer::deserialize(const std::string& filePath) {
    YAML::Node config = YAML::LoadFile(filePath);

    std::vector<stt::StrongType> types{};
    for(int i = 0; i < config["StrongTypes"].size(); i++) {
        types.push_back(deserializeStrongType(config["StrongTypes"][i]));
    }

    std::vector<stt::StrongLiteral> literals{};
    for(int i = 0; i < config["StrongLiterals"].size(); i++) {
        literals.push_back(deserializeStrongLiteral(config["StrongLiterals"][i]));
    }

    return stt::StrongTypeSet(types, literals);
}

stt::StrongLiteral YamlDeserializer::deserializeStrongLiteral(YAML::Node node) {
    return {node["Suffix"].as<std::string>(), node["ArgType"].as<std::string>(),
            node["ResType"].as<std::string>()};
}


stt::StrongType YamlDeserializer::deserializeStrongType(YAML::Node node) {
    stt::StrongType::Builder builder;

    builder.setTypeName(node["TypeName"].as<std::string>())
            ->setWraps(node["Wraps"].as<std::string>());

    std::vector<stt::BinaryOperation> binOps{};
    for(int i = 0; i < node["BinaryOperations"].size(); i++) {
        binOps.push_back(deserializeBinaryOperation(node["BinaryOperations"][i]));
    }
    builder.setBinOps(binOps);

    std::vector<stt::UnaryOperation> uniOps{};
    for(int i = 0; i < node["UnaryOperations"].size(); i++) {
        uniOps.push_back(deserializeUnaryOperation(node["UnaryOperations"][i]));
    }
    builder.setUniOps(uniOps);

    return builder.build();
}

stt::BinaryOperation YamlDeserializer::deserializeBinaryOperation(YAML::Node node) {
    return {node["Operation"].as<std::string>(), node["ArgType"].as<std::string>(),
            node["ResType"].as<std::string>()};
}

stt::UnaryOperation YamlDeserializer::deserializeUnaryOperation(YAML::Node node) {
    return {node["Operation"].as<std::string>(), node["ResType"].as<std::string>()};
}
