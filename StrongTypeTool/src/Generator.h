//
// Created by waschbar on 26.01.22.
//

#ifndef STRONGTYPETOOL_GENERATOR_H
#define STRONGTYPETOOL_GENERATOR_H


#include <boost/filesystem.hpp>
#include "Entities/StrongTypeSet.h"

class Generator {
    using path = boost::filesystem::path;
public:
    explicit Generator(const path& configPath);
    Generator(const path& configPath, const path& rootPath, bool isRootPathRelative = false);

    bool validate();
    bool generate(bool headerOnly = false);

private:
    stt::StrongTypeSet loadConfiguration();
    bool generateStrongType(const stt::StrongType& type, const std::vector<stt::StrongType>& dependencyList, bool headerOnly);
    bool generateCMakeLists(const stt::StrongTypeSet& strongTypeSet, bool headerOnly);

private:
    path configPath, rootPath;
};


#endif //STRONGTYPETOOL_GENERATOR_H
