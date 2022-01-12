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

stt::StrongType::Builder *stt::StrongType::Builder::setUniOps(std::vector<stt::UnaryOperation> unaryOperations) {
    this->unaryOperations = std::move(unaryOperations);
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

const std::vector<stt::UnaryOperation> &stt::StrongType::getUnaryOperations() const {
    return this->unaryOperations;
}

stt::StrongType::StrongType(const stt::StrongType::Builder &builder)
    : typeName(builder.typeName), wraps(builder.wraps), binaryOperations(builder.binaryOperations),
    unaryOperations(builder.unaryOperations) {}
