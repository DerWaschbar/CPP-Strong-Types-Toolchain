//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#ifndef STRONGTYPETOOL_EMPTYFIELDSRULE_H
#define STRONGTYPETOOL_EMPTYFIELDSRULE_H

#include "../ValidationRule.h"

class EmptyFieldsRule : public ValidationRule {
public:
    std::vector<ValidationResult> validate(const stt::StrongTypeSet& typeSet) override;
};


#endif//STRONGTYPETOOL_EMPTYFIELDSRULE_H
