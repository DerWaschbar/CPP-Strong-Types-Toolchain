//
// Created by waschbar on 11.01.22.
//

#ifndef STRONGTYPETOOL_YAMLDESERIALIZER_H
#define STRONGTYPETOOL_YAMLDESERIALIZER_H


#include <vector>
#include "yaml-cpp/yaml.h"

#include "Deserializer.h"

class YamlDeserializer : public Deserializer {
public:
    stt::StrongTypeSet deserialize(const std::string& filePath) override;

    stt::StrongLiteral deserializeStrongLiteral(YAML::Node node);
    stt::StrongType deserializeStrongType(YAML::Node node);
    stt::BinaryOperation deserializeBinaryOperation(YAML::Node node);
    stt::UnaryOperation deserializeUnaryOperation(YAML::Node node);
};


#endif //STRONGTYPETOOL_YAMLDESERIALIZER_H
