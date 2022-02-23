//
// Created by waschbar on 11.01.22.
//

#include "BinaryOperation.h"

const std::string &stt::BinaryOperation::getOperation() const {
    return operation;
}

const std::string &stt::BinaryOperation::getArgType() const {
    return argType;
}

const std::string &stt::BinaryOperation::getResType() const {
    return resType;
}

bool stt::BinaryOperation::isBinaryAssignment() const {
    return (operation.size() == 2 && operation[0] != '=' && operation[1] == '=')
        || operation == "<<=" || operation == ">>=";
}
