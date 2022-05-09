//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#ifndef STRONGTYPETOOL_VALIDATOR_H
#define STRONGTYPETOOL_VALIDATOR_H

#include "../Deserializer/YamlDeserializer.h"
#include "Rules/BinaryAssignmentTypeRule.h"
#include "Rules/EmptyFieldsRule.h"
#include "Rules/LiteralsArgTypeRule.h"
#include "Rules/LiteralsResTypeRule.h"
#include "ValidationRule.h"
#include <utility>
#include <vector>

class Validator {
public:
    explicit Validator(std::vector<ValidationRule*> rules = Validator::basicValidationRules)
        : rules(std::move(rules)) {}

    void addRule(ValidationRule* rule) { rules.push_back(rule); }
    void setDeserializer(Deserializer* otherDeserializer) {
        this->deserializer = otherDeserializer;
    }
    std::vector<ValidationRule*> getRules() const { return rules; }

    std::vector<ValidationResult> validate(const stt::StrongTypeSet& typeSet);
    std::vector<ValidationResult> validate(const std::string& configPath);

public:
    inline static const std::vector<ValidationRule*> basicValidationRules = {
            new BinaryAssignmentTypeRule(), new EmptyFieldsRule(), new LiteralsArgTypeRule(),
            new LiteralsResTypeRule()};

private:
    std::vector<ValidationRule*> rules;
    std::optional<Deserializer*> deserializer = {};
};

#endif//STRONGTYPETOOL_VALIDATOR_H
