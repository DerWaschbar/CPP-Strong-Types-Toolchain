//
// Created by waschbar on 24.01.22.
//

#ifndef STRONGTYPETOOL_CPPHSERIALIZER_H
#define STRONGTYPETOOL_CPPHSERIALIZER_H


#include <string>
#include <vector>
#include "../Entities/StrongType.h"

class CPPHSerializer {
public:
    static std::vector<std::string> serialize(const std::vector<stt::StrongType>& strongTypes);
    static std::string serializeStrongType(const stt::StrongType& strongType);
    static std::string serializeBinaryOperation(const stt::BinaryOperation& binaryOperation);
    static std::string serializeUnaryOperation(const stt::UnaryOperation& unaryOperation);
};


#endif //STRONGTYPETOOL_CPPHSERIALIZER_H
