//
// Created by Beka Grdzelishvili (DerWaschbar) on 27.03.22.
//

#include "LiteralSerializer.h"
#include <inja/inja.hpp>
#include <nlohmann/json.hpp>

std::vector<std::string> LiteralSerializer::serialize(const stt::StrongTypeSet& strongTypeSet) {
    std::string ops;
    for(const stt::StrongLiteral& literal : strongTypeSet.getLiterals()) {
        ops += serializeStrongLiteralOp(literal) + "\n";
    }

    nlohmann::json literals;
    literals["name"] = "StrongLiterals";
    literals["ops"] = ops;

    return {inja::render((&templateManager)->getTemplate(Template::T_Literal), literals)};
}

std::string LiteralSerializer::serializeStrongLiteralOp(const stt::StrongLiteral& strongLiteral) {
    nlohmann::json opJson;
    opJson["res"] = strongLiteral.getResType();
    opJson["arg"] = strongLiteral.getArgType();
    opJson["suffix"] = strongLiteral.getSuffix();

    return inja::render((&templateManager)->getTemplate(Template::T_LiteralOp), opJson);
}
