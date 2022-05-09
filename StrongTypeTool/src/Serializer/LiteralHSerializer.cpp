//
// Created by Beka Grdzelishvili (DerWaschbar) on 27.03.22.
//

#include "LiteralHSerializer.h"
#include <boost/algorithm/string/case_conv.hpp>
#include <inja/inja.hpp>
#include <nlohmann/json.hpp>

std::vector<std::string> LiteralHSerializer::serialize(const stt::StrongTypeSet& strongTypeSet) {
    std::string ops;
    for(const stt::StrongLiteral& literal : strongTypeSet.getLiterals()) {
        ops += serializeStrongLiteralOp(literal);
    }

    nlohmann::json literals;
    literals["name"] = "StrongLiterals";
    literals["NAME"] = boost::to_upper_copy<std::string>(literals["name"]);
    literals["ops"] = ops;
    literals["includes"] = serializeIncludes(strongTypeSet.getLiteralsDependency());

    return {inja::render((&templateManager)->getTemplate(Template::T_LiteralHeader), literals)};
}

std::string LiteralHSerializer::serializeStrongLiteralOp(const stt::StrongLiteral& strongLiteral) {
    nlohmann::json opJson;
    opJson["res"] = strongLiteral.getResType();
    opJson["arg"] = strongLiteral.getArgType();
    opJson["suffix"] = strongLiteral.getSuffix();

    return inja::render((&templateManager)->getTemplate(Template::T_LiteralOpHeader), opJson);
}

std::string LiteralHSerializer::serializeIncludes(const std::set<std::string>& includedTypes) {
    std::string includes;

    nlohmann::json includeData;
    for(const std::string& typeName : includedTypes) {
        includeData["include_path"] = typeName + ".h";
        includes += inja::render((&templateManager)->getTemplate(Template::T_Include), includeData);
    }
    return includes;
}
