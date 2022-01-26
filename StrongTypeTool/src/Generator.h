//
// Created by waschbar on 26.01.22.
//

#ifndef STRONGTYPETOOL_GENERATOR_H
#define STRONGTYPETOOL_GENERATOR_H


#include <boost/filesystem.hpp>
#include "Entities/StrongType.h"

class Generator {
    using path = boost::filesystem::path;
public:
    explicit Generator(const path& configPath);
    Generator(const path& configPath, const path& rootPath, bool isRootPathRelative = false);

    bool validate();
    bool generate();

private:
    std::vector<stt::StrongType> loadConfiguration();
    bool generateStrongType(stt::StrongType type);

private:
    path configPath, rootPath;
};


#endif //STRONGTYPETOOL_GENERATOR_H
