//
// Created by waschbar on 27.03.22.
//

#ifndef STRONGTYPETOOL_LITERALSERIALIZER_H
#define STRONGTYPETOOL_LITERALSERIALIZER_H


#include "TemplateManager.h"
#include "../Entities/StrongTypeSet.h"

class LiteralSerializer {
public:
    explicit LiteralSerializer(TemplateManager templateManager) : templateManager(std::move(templateManager)) {}
    LiteralSerializer() : LiteralSerializer(TemplateManager()) {}
public:
    std::vector<std::string> serialize(const stt::StrongTypeSet& strongTypeSet);
    std::string serializeStrongLiteralOp(const stt::StrongLiteral& strongLiteral);

private:
    const TemplateManager templateManager;
};


#endif //STRONGTYPETOOL_LITERALSERIALIZER_H
