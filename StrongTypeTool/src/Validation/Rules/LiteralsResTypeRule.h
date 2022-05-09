//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#ifndef STRONGTYPETOOL_LITERALSRESTYPERULE_H
#define STRONGTYPETOOL_LITERALSRESTYPERULE_H

#include "../ValidationRule.h"

class LiteralsResTypeRule : public ValidationRule {
public:
    std::vector<ValidationResult> validate(const stt::StrongTypeSet& typeSet) override;
};


#endif//STRONGTYPETOOL_LITERALSRESTYPERULE_H
