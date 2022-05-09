//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#ifndef STRONGTYPETOOL_VALIDATIONRULE_H
#define STRONGTYPETOOL_VALIDATIONRULE_H

#include <vector>

#include "../Entities/StrongTypeSet.h"
#include "ValidationResult.h"

class ValidationRule {
public:
    virtual std::vector<ValidationResult> validate(const stt::StrongTypeSet& typeSet) = 0;
};


#endif//STRONGTYPETOOL_VALIDATIONRULE_H
