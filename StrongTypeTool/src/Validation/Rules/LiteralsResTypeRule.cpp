//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#include "LiteralsResTypeRule.h"
#include <algorithm>

std::vector<ValidationResult> LiteralsResTypeRule::validate(const stt::StrongTypeSet& typeSet) {
    std::vector<std::string> typeNames;
    for(const stt::StrongType& type : typeSet.getTypes()) {
        typeNames.push_back(type.getTypeName());
    }

    std::vector<ValidationResult> results;

    for(const stt::StrongLiteral& literal : typeSet.getLiterals()) {
        if(std::count(typeNames.begin(), typeNames.end(), literal.getResType()) == 0) {
            results.emplace_back("[LiteralsResTypeRule] - Literal with suffix '" +
                                         literal.getSuffix() +
                                         "' does not have strong type as ResType.",
                                 ValidationResultType::Error);
        }
    }

    return results;
}
