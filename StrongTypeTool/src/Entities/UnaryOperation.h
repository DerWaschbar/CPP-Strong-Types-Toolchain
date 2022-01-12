//
// Created by waschbar on 12.01.22.
//

#ifndef STRONGTYPETOOL_UNARYOPERATION_H
#define STRONGTYPETOOL_UNARYOPERATION_H

#include <string>

namespace stt {
    class UnaryOperation {
    private:
        std::string operation;
        std::string resType;
    public:
        const std::string &getOperation() const;
        const std::string &getResType() const;

        UnaryOperation(std::string operation, std::string resType)
        : operation(std::move(operation)), resType(std::move(resType)) {}
    };
}


#endif //STRONGTYPETOOL_UNARYOPERATION_H
