//
// Created by waschbar on 29.03.22.
//

#ifndef STRONGTYPETOOL_LITERALSARGTYPERULE_H
#define STRONGTYPETOOL_LITERALSARGTYPERULE_H

#include "../ValidationRule.h"

class LiteralsArgTypeRule : public ValidationRule {
public:
    std::vector<ValidationResult> validate(const stt::StrongTypeSet& typeSet) override;

private:
    static const inline std::vector<std::string> allowedTypes = {
      "const char*", "const char *",
      "unsigned long long int",
      "unsigned long long",
      "long double",
      "char",
      "wchar_t",
      "char8_t",
      "char16_t",
      "char32_t"
    };
};


#endif //STRONGTYPETOOL_LITERALSARGTYPERULE_H
