//
// Created by Beka Grdzelishvili (DerWaschbar) on 26.01.22.
//

#ifndef STRONGTYPETOOL_CPPSERIALIZER_H
#define STRONGTYPETOOL_CPPSERIALIZER_H


#include "../Entities/StrongTypeSet.h"
#include "TemplateManager.h"
#include <string>
#include <vector>

class CPPSerializer {
public:
    explicit CPPSerializer(TemplateManager templateManager)
        : templateManager(std::move(templateManager)) {}
    CPPSerializer() : CPPSerializer(TemplateManager()) {}

public:
    std::vector<std::string> serialize(const stt::StrongTypeSet& strongTypeSet);
    std::string serializeStrongType(const stt::StrongType& strongType);
    std::string serializeBinaryOperation(const stt::BinaryOperation& binaryOperation);
    std::string serializeUnaryOperation(const stt::UnaryOperation& unaryOperation);

private:
    const TemplateManager templateManager;
};


#endif//STRONGTYPETOOL_CPPSERIALIZER_H
