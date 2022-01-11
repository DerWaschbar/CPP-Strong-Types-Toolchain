//
// Created by waschbar on 11.01.22.
//

#ifndef STRONGTYPETOOL_STRONGTYPE_H
#define STRONGTYPETOOL_STRONGTYPE_H


#include <utility>
#include <vector>
#include <string>

#include "BinaryOperation.h"

namespace stt {
    class StrongType {
    private:
        std::string typeName;
        std::string wraps;
        std::vector<stt::BinaryOperation> binaryOperations;
    public:
        const std::string &getTypeName() const;
        const std::string &getWraps() const;
        const std::vector<stt::BinaryOperation> &getBinaryOperations() const;

        StrongType(std::string typeName, std::string wraps, std::vector<stt::BinaryOperation> binOps)
            : typeName(std::move(typeName)), wraps(std::move(wraps)), binaryOperations(std::move(binOps)) {}
    public:
        class Builder {
        public:
            std::string typeName;
            std::string wraps;
            std::vector<stt::BinaryOperation> binaryOperations;

            Builder* setTypeName(std::string typeName);
            Builder* setWraps(std::string wraps);
            Builder* setBinOps(std::vector<stt::BinaryOperation> binaryOperations);
            StrongType build() { return StrongType(*this); }
        };
        explicit StrongType(const Builder& builder)
          : typeName(builder.typeName), wraps(builder.wraps),
          binaryOperations(builder.binaryOperations) {}
    };
}



#endif //STRONGTYPETOOL_STRONGTYPE_H
