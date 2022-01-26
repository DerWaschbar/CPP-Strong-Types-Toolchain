//
// Created by waschbar on 26.01.22.
//

#ifndef STRONGTYPETOOL_CPPSERIALIZER_H
#define STRONGTYPETOOL_CPPSERIALIZER_H


#include <string>
#include <vector>
#include "../Entities/StrongType.h"

class CPPSerializer {
public:
    static std::vector<std::string> serialize(const std::vector<stt::StrongType>& strongTypes);
    static std::string serializeStrongType(const stt::StrongType& strongType);
    static std::string serializeBinaryOperation(const stt::BinaryOperation& binaryOperation);
    static std::string serializeUnaryOperation(const stt::UnaryOperation& unaryOperation);
};


#endif //STRONGTYPETOOL_CPPSERIALIZER_H
