//
// Created by waschbar on 27.03.22.
//

#ifndef STRONGTYPETOOL_LITERALHSERIALIZER_H
#define STRONGTYPETOOL_LITERALHSERIALIZER_H

#include "TemplateManager.h"
#include "../Entities/StrongTypeSet.h"

class LiteralHSerializer {
public:
    explicit LiteralHSerializer(TemplateManager templateManager) : templateManager(std::move(templateManager)) {}
    LiteralHSerializer() : LiteralHSerializer(TemplateManager()) {}
public:
    std::vector<std::string> serialize(const stt::StrongTypeSet& strongTypeSet);
    std::string serializeStrongLiteralOp(const stt::StrongLiteral& strongLiteral);
private:
    std::string serializeIncludes(const std::set<std::string>& includedTypes);

private:
    const TemplateManager templateManager;
};


#endif //STRONGTYPETOOL_LITERALHSERIALIZER_H
