//
// Created by waschbar on 29.03.22.
//

#include <algorithm>
#include <iostream>
#include "LiteralsArgTypeRule.h"

std::vector<ValidationResult> LiteralsArgTypeRule::validate(const stt::StrongTypeSet &typeSet) {
    std::vector<ValidationResult> results;

    for(const stt::StrongLiteral& literal : typeSet.getLiterals()) {
        if(std::count(LiteralsArgTypeRule::allowedTypes.begin(), LiteralsArgTypeRule::allowedTypes.end(), literal.getArgType()) == 0) {
            results.emplace_back(
                    "[LiteralsArgTypeRule] - Literal with suffix '" + literal.getSuffix() + "' has invalid ArgType.",
                    ValidationResultType::Error
            );
        }
    }

    return results;
}
