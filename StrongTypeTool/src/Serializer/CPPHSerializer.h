//
// Created by waschbar on 24.01.22.
//

#ifndef STRONGTYPETOOL_CPPHSERIALIZER_H
#define STRONGTYPETOOL_CPPHSERIALIZER_H


#include <string>
#include <utility>
#include <vector>
#include "../Entities/StrongTypeSet.h"
#include "TemplateManager.h"

class CPPHSerializer {
public:
    explicit CPPHSerializer(TemplateManager templateManager) : templateManager(std::move(templateManager)) {}
    CPPHSerializer() : CPPHSerializer(TemplateManager()) {}
public:
    std::vector<std::string> serialize(const stt::StrongTypeSet& strongTypeSet);
    std::string serializeStrongType(const stt::StrongType& strongType);
    std::string serializeBinaryOperation(const stt::BinaryOperation& binaryOperation);
    std::string serializeUnaryOperation(const stt::UnaryOperation& unaryOperation);

private:
    const TemplateManager templateManager;
};


#endif //STRONGTYPETOOL_CPPHSERIALIZER_H
