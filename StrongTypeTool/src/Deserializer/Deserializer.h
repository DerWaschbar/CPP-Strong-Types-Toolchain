//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/8/22.
//

#ifndef STRONGTYPETOOL_DESERIALIZER_H
#define STRONGTYPETOOL_DESERIALIZER_H

#include "../Entities/StrongTypeSet.h"

class Deserializer {
public:
    virtual stt::StrongTypeSet deserialize(const std::string& filePath) = 0;
};


#endif//STRONGTYPETOOL_DESERIALIZER_H
