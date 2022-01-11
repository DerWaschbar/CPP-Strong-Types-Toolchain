//
// Created by waschbar on 11.01.22.
//

#ifndef STRONGTYPETOOL_YAMLDESERIALIZER_H
#define STRONGTYPETOOL_YAMLDESERIALIZER_H


#include <vector>
#include "yaml-cpp/yaml.h"

#include "../Entities/StrongType.h"

class YamlDeserializer {
public:
    static std::vector<stt::StrongType> deserialize(std::string filePath);
    static stt::StrongType deserializeStrongType(YAML::Node node);
    static stt::BinaryOperation deserializeBinaryOperation(YAML::Node node);
private:
    YamlDeserializer() = default;
};


#endif //STRONGTYPETOOL_YAMLDESERIALIZER_H
