//
// Created by waschbar on 29.03.22.
//

#ifndef STRONGTYPETOOL_VALIDATOR_H
#define STRONGTYPETOOL_VALIDATOR_H

#include <utility>
#include <vector>
#include "ValidationRule.h"

class Validator {
public:
    Validator() = default;
    explicit Validator(std::vector<ValidationRule*> rules) : rules(std::move(rules)) {}

    void addRule(ValidationRule* rule) { rules.push_back(rule); }
    std::vector<ValidationRule*> getRules() const { return rules; }

    std::vector<ValidationResult> validate(const stt::StrongTypeSet& typeSet);

private:
    std::vector<ValidationRule*> rules;
};


#endif //STRONGTYPETOOL_VALIDATOR_H
