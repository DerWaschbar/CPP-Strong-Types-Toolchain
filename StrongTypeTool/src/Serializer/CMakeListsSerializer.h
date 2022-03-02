//
// Created by waschbar on 28.02.22.
//

#ifndef STRONGTYPETOOL_CMAKELISTSSERIALIZER_H
#define STRONGTYPETOOL_CMAKELISTSSERIALIZER_H


#include <string>

#include "../Entities/StrongTypeSet.h"

class CMakeListsSerializer {
public:
    explicit CMakeListsSerializer() = default;

public:
    std::string serialize(const stt::StrongTypeSet& strongTypeSet, bool headerOnly);
};


#endif //STRONGTYPETOOL_CMAKELISTSSERIALIZER_H
