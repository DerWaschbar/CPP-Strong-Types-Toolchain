//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#include "Validator.h"

#include "../Deserializer/YamlDeserializer.h"

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

std::vector<ValidationResult> Validator::validate(const std::string& configPath) {
    if(this->deserializer.has_value())
        return validate(this->deserializer.value()->deserialize(configPath));
    return validate(YamlDeserializer().deserialize(configPath));
}
