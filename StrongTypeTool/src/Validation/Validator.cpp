//
// Created by waschbar on 29.03.22.
//

#include "Validator.h"

std::vector<ValidationResult> Validator::validate(const stt::StrongTypeSet& typeSet) {
    std::vector<ValidationResult> vResults;

    for(ValidationRule* rule : this->rules) {
        std::vector<ValidationResult> results = rule->validate(typeSet);
        for(const ValidationResult& result : results) {
            vResults.push_back(result);
        }
    }

    return vResults;
}