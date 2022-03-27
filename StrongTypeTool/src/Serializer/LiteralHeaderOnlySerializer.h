//
// Created by waschbar on 27.03.22.
//

#ifndef STRONGTYPETOOL_LITERALHEADERONLYSERIALIZER_H
#define STRONGTYPETOOL_LITERALHEADERONLYSERIALIZER_H


#include "TemplateManager.h"
#include "../Entities/StrongTypeSet.h"

class LiteralHeaderOnlySerializer {
public:
    explicit LiteralHeaderOnlySerializer(TemplateManager templateManager) : templateManager(std::move(templateManager)) {}
    LiteralHeaderOnlySerializer() : LiteralHeaderOnlySerializer(TemplateManager()) {}
public:
    std::vector<std::string> serialize(const stt::StrongTypeSet& strongTypeSet);
    std::string serializeStrongLiteralOp(const stt::StrongLiteral& strongLiteral);
private:
    std::string serializeIncludes(const std::set<std::string>& includedTypes);

private:
    const TemplateManager templateManager;
};


#endif //STRONGTYPETOOL_LITERALHEADERONLYSERIALIZER_H
