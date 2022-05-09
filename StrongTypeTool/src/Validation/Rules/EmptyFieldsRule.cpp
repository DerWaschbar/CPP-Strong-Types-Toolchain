//
// Created by Beka Grdzelishvili (DerWaschbar) on 29.03.22.
//

#include "EmptyFieldsRule.h"

std::vector<ValidationResult> EmptyFieldsRule::validate(const stt::StrongTypeSet& typeSet) {
    std::vector<ValidationResult> results;

    for(const stt::StrongType& type : typeSet.getTypes()) {
        if(type.getTypeName().length() == 0) {
            results.emplace_back("[EmptyFieldsRule] - Type name ('" + type.getTypeName() +
                                         "') is empty.",
                                 ValidationResultType::Error);
        }
        if(type.getWraps().length() == 0) {
            results.emplace_back("[EmptyFieldsRule] - Wrapped type ('" + type.getWraps() +
                                         "') in type '" + type.getTypeName() + "' is empty.",
                                 ValidationResultType::Error);
        }

        for(const stt::BinaryOperation& op : type.getBinaryOperations()) {
            if(op.getOperation().length() == 0) {
                results.emplace_back("[EmptyFieldsRule] - Operation name ('" + type.getTypeName() +
                                             "') is empty.",
                                     ValidationResultType::Error);
            }
            if(op.getResType().length() == 0) {
                results.emplace_back("[EmptyFieldsRule] - ResType ('" + op.getResType() +
                                             "') in operation '" + op.getOperation() +
                                             "' is empty.",
                                     ValidationResultType::Error);
            }
            if(op.getArgType().length() == 0) {
                results.emplace_back("[EmptyFieldsRule] - ArgType ('" + op.getArgType() +
                                             "') in operation '" + op.getOperation() +
                                             "' is empty.",
                                     ValidationResultType::Error);
            }
        }
        for(const stt::UnaryOperation& op : type.getUnaryOperations()) {
            if(op.getOperation().length() == 0) {
                results.emplace_back("[EmptyFieldsRule] - Operation name ('" + type.getTypeName() +
                                             "') is empty.",
                                     ValidationResultType::Error);
            }
            if(op.getResType().length() == 0) {
                results.emplace_back("[EmptyFieldsRule] - ResType ('" + op.getResType() +
                                             "') in operation '" + op.getOperation() +
                                             "' is empty.",
                                     ValidationResultType::Error);
            }
        }
    }

    for(const stt::StrongLiteral& literal : typeSet.getLiterals()) {
        if(literal.getSuffix().length() == 0) {
            results.emplace_back("[EmptyFieldsRule] - Literal suffix ('" + literal.getSuffix() +
                                         "') is empty.",
                                 ValidationResultType::Error);
        }
        if(literal.getArgType().length() == 0) {
            results.emplace_back("[EmptyFieldsRule] - Literal's ArgType ('" + literal.getArgType() +
                                         "') in literal with suffix '" + literal.getSuffix() +
                                         "' is empty.",
                                 ValidationResultType::Error);
        }
        if(literal.getResType().length() == 0) {
            results.emplace_back("[EmptyFieldsRule] - Literal's ResType ('" + literal.getResType() +
                                         "') in literal with suffix '" + literal.getSuffix() +
                                         "' is empty.",
                                 ValidationResultType::Error);
        }
    }

    return results;
}
