//
// Created by waschbar on 28.02.22.
//

#include "CMakeListsSerializer.h"

std::string CMakeListsSerializer::serialize(const stt::StrongTypeSet &strongTypeSet) {
    std::string cmake = "add_library(StrongTypes";

    for(const stt::StrongType& type : strongTypeSet.getTypes()) {
        cmake += "\n\t\t" + type.getTypeName() + ".cpp"
                 "\n\t\t" + type.getTypeName() + ".h";
    }

    cmake += ")";
    return cmake;
}
