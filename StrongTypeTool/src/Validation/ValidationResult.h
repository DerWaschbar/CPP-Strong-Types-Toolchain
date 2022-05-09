//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#ifndef STRONGTYPETOOL_VALIDATIONRESULT_H
#define STRONGTYPETOOL_VALIDATIONRESULT_H

#include <string>
#include <utility>

enum class ValidationResultType { Warning, Error };

class ValidationResult {
public:
    explicit ValidationResult(std::string result,
                              ValidationResultType type = ValidationResultType::Error)
        : result(std::move(result)), type(type) {}

    const std::string& getResult() const { return result; }
    ValidationResultType getType() const { return type; }
    bool isWarning() const { return type == ValidationResultType::Warning; }
    bool isError() const { return type == ValidationResultType::Error; }

private:
    std::string result;
    ValidationResultType type;
};


#endif//STRONGTYPETOOL_VALIDATIONRESULT_H
