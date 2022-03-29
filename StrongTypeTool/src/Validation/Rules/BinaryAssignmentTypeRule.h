//
// Created by waschbar on 29.03.22.
//

#ifndef STRONGTYPETOOL_BINARYASSIGNMENTTYPERULE_H
#define STRONGTYPETOOL_BINARYASSIGNMENTTYPERULE_H

#include "../ValidationRule.h"

class BinaryAssignmentTypeRule : public ValidationRule {
public:
    std::vector<ValidationResult> validate(const stt::StrongTypeSet& typeSet) override;
};


#endif //STRONGTYPETOOL_BINARYASSIGNMENTTYPERULE_H
