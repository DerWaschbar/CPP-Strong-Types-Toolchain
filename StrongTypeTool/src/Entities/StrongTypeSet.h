//
// Created by waschbar on 10.02.22.
//

#ifndef STRONGTYPETOOL_STRONGTYPESET_H
#define STRONGTYPETOOL_STRONGTYPESET_H


#include <utility>

#include "StrongType.h"

namespace stt {
    class StrongTypeSet {
    public:
        explicit StrongTypeSet(std::vector<stt::StrongType> types) : types(std::move(types)) {}

        std::vector<stt::StrongType> getTypes() const { return types; }

    private:
        std::vector<stt::StrongType> types;
    };
}


#endif //STRONGTYPETOOL_STRONGTYPESET_H
