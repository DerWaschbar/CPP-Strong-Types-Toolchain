//
// Created by waschbar on 11.01.22.
//

#ifndef STRONGTYPETOOL_YAMLDESERIALIZER_H
#define STRONGTYPETOOL_YAMLDESERIALIZER_H


#include <vector>
#include "yaml-cpp/yaml.h"

#include "../Entities/StrongTypeSet.h"

class YamlDeserializer {
public:
    static stt::StrongTypeSet deserialize(const std::string& filePath);
    static stt::StrongType deserializeStrongType(YAML::Node node);
    static stt::BinaryOperation deserializeBinaryOperation(YAML::Node node);
    static stt::UnaryOperation deserializeUnaryOperation(YAML::Node node);
private:
    YamlDeserializer() = default;
};


#endif //STRONGTYPETOOL_YAMLDESERIALIZER_H
