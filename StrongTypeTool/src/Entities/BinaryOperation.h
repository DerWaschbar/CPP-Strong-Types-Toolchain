//
// Created by Beka Grdzelishvili (DerWaschbar) on 11.01.22.
//

#ifndef STRONGTYPETOOL_BINARYOPERATION_H
#define STRONGTYPETOOL_BINARYOPERATION_H

#include <string>
#include <utility>

namespace stt {
    class BinaryOperation {
    private:
        std::string operation;
        std::string argType;
        std::string resType;

    public:
        const std::string& getOperation() const;
        const std::string& getArgType() const;
        const std::string& getResType() const;

        bool isBinaryAssignment() const;

        BinaryOperation(std::string operation, std::string argType, std::string resType)
            : operation(std::move(operation)), argType(std::move(argType)),
              resType(std::move(resType)) {}
    };
}// namespace stt


#endif//STRONGTYPETOOL_BINARYOPERATION_H
