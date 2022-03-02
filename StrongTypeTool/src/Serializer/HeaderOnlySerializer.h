//
// Created by waschbar on 28.02.22.
//

#ifndef STRONGTYPETOOL_HEADERONLYSERIALIZER_H
#define STRONGTYPETOOL_HEADERONLYSERIALIZER_H


#include "TemplateManager.h"
#include "../Entities/StrongTypeSet.h"

class HeaderOnlySerializer {
public:
    explicit HeaderOnlySerializer(TemplateManager templateManager) : templateManager(std::move(templateManager)) {}
    HeaderOnlySerializer() : HeaderOnlySerializer(TemplateManager()) {}

public:
    std::vector<std::string> serialize(const stt::StrongTypeSet &strongTypeSet);
    std::string serializeStrongType(const stt::StrongType &strongType, const std::vector<stt::StrongType> &includedTypes);

private:
    std::pair<std::string, std::string> serializeBinaryOperation(const stt::BinaryOperation &binaryOperation);
    std::pair<std::string, std::string> serializeUnaryOperation(const stt::UnaryOperation &unaryOperation);
    std::string serializeIncludes(const std::vector<stt::StrongType> &includedTypes);

private:
    const TemplateManager templateManager;
};

#endif //STRONGTYPETOOL_HEADERONLYSERIALIZER_H
