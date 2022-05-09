//
// Created by Beka Grdzelishvili (DerWaschbar) on 27.03.22.
//

#include "LiteralHeaderOnlySerializer.h"
#include <boost/algorithm/string/case_conv.hpp>
#include <inja/inja.hpp>
#include <nlohmann/json.hpp>

std::vector<std::string>
LiteralHeaderOnlySerializer::serialize(const stt::StrongTypeSet& strongTypeSet) {
    std::string ops;
    for(const stt::StrongLiteral& literal : strongTypeSet.getLiterals()) {
        ops += "inline " + serializeStrongLiteralOp(literal) + "\n";
    }

    nlohmann::json literals;
    literals["name"] = "StrongLiterals";
    literals["NAME"] = boost::to_upper_copy<std::string>(literals["name"]);
    literals["ops"] = ops;
    literals["includes"] = serializeIncludes(strongTypeSet.getLiteralsDependency());

    return {inja::render((&templateManager)->getTemplate(Template::T_LiteralHeaderOnly), literals)};
}

std::string
LiteralHeaderOnlySerializer::serializeStrongLiteralOp(const stt::StrongLiteral& strongLiteral) {
    nlohmann::json opJson;
    opJson["res"] = strongLiteral.getResType();
    opJson["arg"] = strongLiteral.getArgType();
    opJson["suffix"] = strongLiteral.getSuffix();

    return inja::render((&templateManager)->getTemplate(Template::T_LiteralOp), opJson);
}

std::string
LiteralHeaderOnlySerializer::serializeIncludes(const std::set<std::string>& includedTypes) {
    std::string includes;

    nlohmann::json includeData;
    for(const std::string& typeName : includedTypes) {
        includeData["include_path"] = typeName + ".h";
        includes += inja::render((&templateManager)->getTemplate(Template::T_Include), includeData);
    }
    return includes;
}
