//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#include "BinaryAssignmentTypeRule.h"
#include <iostream>

std::vector<ValidationResult>
BinaryAssignmentTypeRule::validate(const stt::StrongTypeSet& typeSet) {
    std::vector<ValidationResult> results;

    for(const stt::StrongType& type : typeSet.getTypes()) {
        for(const stt::BinaryOperation& op : type.getBinaryOperations()) {
            if(op.isBinaryAssignment() && op.getResType() != type.getTypeName()) {
                results.emplace_back("[BinaryAssignmentTypeRule] - Operation " + op.getOperation() +
                                             " in type " + type.getTypeName() +
                                             " has invalid result type. "
                                             "Expected: " +
                                             type.getTypeName() + " Found: " + op.getResType() +
                                             ".",
                                     ValidationResultType::Error);
            }
        }
    }

    return results;
}
