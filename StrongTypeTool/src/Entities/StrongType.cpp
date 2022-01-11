//
// Created by waschbar on 11.01.22.
//

#include "StrongType.h"

#include <utility>

stt::StrongType::Builder *stt::StrongType::Builder::setTypeName(std::string typeName) {
    this->typeName = std::move(typeName);
    return this;
}

stt::StrongType::Builder *stt::StrongType::Builder::setWraps(std::string wraps) {
    this->wraps = std::move(wraps);
    return this;
}

stt::StrongType::Builder *stt::StrongType::Builder::setBinOps(std::vector<stt::BinaryOperation> binaryOperations) {
    this->binaryOperations = std::move(binaryOperations);
    return this;
}

const std::string &stt::StrongType::getTypeName() const {
    return this->typeName;
}

const std::string &stt::StrongType::getWraps() const {
    return this->wraps;
}

const std::vector<stt::BinaryOperation> &stt::StrongType::getBinaryOperations() const {
    return this->binaryOperations;
}
