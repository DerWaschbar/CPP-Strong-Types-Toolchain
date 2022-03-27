//
// Created by waschbar on 28.02.22.
//

#include "CMakeListsSerializer.h"

std::string CMakeListsSerializer::serialize(const stt::StrongTypeSet &strongTypeSet, bool headerOnly) {
    std::string cmake = "add_library(StrongTypes";
    if(headerOnly)
        cmake += " INTERFACE";

    if(strongTypeSet.hasLiterals()) {
        if(!headerOnly)
            cmake += "\n\t\tStrongLiterals.cpp";
        cmake += "\n\t\tStrongLiterals.h";
    }

    for(const stt::StrongType& type : strongTypeSet.getTypes()) {
        if(!headerOnly)
            cmake += "\n\t\t" + type.getTypeName() + ".cpp";
        cmake += "\n\t\t" + type.getTypeName() + ".h";
    }

    cmake += ")";
    return cmake;
}
