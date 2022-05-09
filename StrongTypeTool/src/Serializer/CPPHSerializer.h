//
// Created by Beka Grdzelishvili (DerWaschbar) on 24.01.22.
//

#ifndef STRONGTYPETOOL_CPPHSERIALIZER_H
#define STRONGTYPETOOL_CPPHSERIALIZER_H


#include "../Entities/StrongTypeSet.h"
#include "TemplateManager.h"
#include <string>
#include <utility>
#include <vector>

class CPPHSerializer {
public:
    explicit CPPHSerializer(TemplateManager templateManager)
        : templateManager(std::move(templateManager)) {}
    CPPHSerializer() : CPPHSerializer(TemplateManager()) {}

public:
    std::vector<std::string> serialize(const stt::StrongTypeSet& strongTypeSet);
    std::string serializeStrongType(const stt::StrongType& strongType,
                                    const std::vector<stt::StrongType>& includedTypes);

private:
    std::string serializeBinaryOperation(const stt::BinaryOperation& binaryOperation);
    std::string serializeUnaryOperation(const stt::UnaryOperation& unaryOperation);
    std::string serializeIncludes(const std::vector<stt::StrongType>& includedTypes);

private:
    const TemplateManager templateManager;
};


#endif//STRONGTYPETOOL_CPPHSERIALIZER_H
