//
// Created by waschbar on 11.01.22.
//

#ifndef STRONGTYPETOOL_STRONGTYPE_H
#define STRONGTYPETOOL_STRONGTYPE_H


#include <utility>
#include <vector>
#include <string>

#include "BinaryOperation.h"
#include "UnaryOperation.h"

namespace stt {
    class StrongType {
    private:
        std::string typeName;
        std::string wraps;
        std::vector<stt::BinaryOperation> binaryOperations;
        std::vector<stt::UnaryOperation> unaryOperations;
    public:
        const std::string &getTypeName() const;
        const std::string &getWraps() const;
        const std::vector<stt::BinaryOperation> &getBinaryOperations() const;
        const std::vector<stt::UnaryOperation> &getUnaryOperations() const;

        StrongType(std::string typeName, std::string wraps, std::vector<stt::BinaryOperation> binOps, std::vector<stt::UnaryOperation> unOps)
            : typeName(std::move(typeName)), wraps(std::move(wraps)), binaryOperations(std::move(binOps)), unaryOperations(std::move(unOps)) {}
    public:
        class Builder {
        public:
            std::string typeName;
            std::string wraps;
            std::vector<stt::BinaryOperation> binaryOperations;
            std::vector<stt::UnaryOperation> unaryOperations;

            Builder* setTypeName(std::string typeName);
            Builder* setWraps(std::string wraps);
            Builder* setBinOps(std::vector<stt::BinaryOperation> binaryOperations);
            Builder* setUniOps(std::vector<stt::UnaryOperation> unaryOperations);
            StrongType build() { return StrongType(*this); }
        };
        explicit StrongType(const Builder& builder);
    };
}



#endif //STRONGTYPETOOL_STRONGTYPE_H
