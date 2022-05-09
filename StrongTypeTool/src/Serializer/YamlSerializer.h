//
// Created by Beka Grdzelishvili (DerWaschbar) on 12.01.22.
//

#ifndef STRONGTYPETOOL_YAMLSERIALIZER_H
#define STRONGTYPETOOL_YAMLSERIALIZER_H

#include "../Entities/StrongTypeSet.h"
#include "yaml-cpp/yaml.h"

class YamlSerializer {
public:
    static YAML::Node serialize(const stt::StrongTypeSet& strongTypeSet);
    static YAML::Node serializeStrongType(const stt::StrongType& strongType);
    static YAML::Node serializeBinaryOperation(const stt::BinaryOperation& binaryOperation);
    static YAML::Node serializeUnaryOperation(const stt::UnaryOperation& unaryOperation);
};


#endif//STRONGTYPETOOL_YAMLSERIALIZER_H
