//
// Created by waschbar on 26.03.22.
//

#ifndef STRONGTYPETOOL_STRONGLITERAL_H
#define STRONGTYPETOOL_STRONGLITERAL_H

#include <string>
#include <utility>

namespace stt {
    class StrongLiteral {
    private:
        std::string suffix;
        std::string argType;
        std::string resType;
    public:
        const std::string &getSuffix() const;
        const std::string &getArgType() const;
        const std::string &getResType() const;

        StrongLiteral(std::string suffix, std::string argType, std::string resType)
        : suffix(std::move(suffix)), argType(std::move(argType)), resType(std::move(resType)) {}
    };
}

#endif //STRONGTYPETOOL_STRONGLITERAL_H
