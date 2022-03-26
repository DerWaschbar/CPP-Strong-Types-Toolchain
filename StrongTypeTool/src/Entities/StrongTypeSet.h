//
// Created by waschbar on 10.02.22.
//

#ifndef STRONGTYPETOOL_STRONGTYPESET_H
#define STRONGTYPETOOL_STRONGTYPESET_H


#include <vector>
#include <map>
#include <set>

#include "StrongType.h"
#include "StrongLiteral.h"

namespace stt {
    class StrongTypeSet {
    public:
        explicit StrongTypeSet(std::vector<stt::StrongType> types, std::vector<stt::StrongLiteral> literals = {});

        std::vector<stt::StrongType> getTypes() const { return types; }
        std::vector<stt::StrongLiteral> getLiterals() const { return literals; }
        std::vector<stt::StrongType> getDependencies(const stt::StrongType& type) const ;
        std::set<std::string> getLiteralsDependency() const { return literalsDependency; }

    private:
        void buildDependencyGraph();
        void resolveDependencies();

    private:
        std::vector<stt::StrongType> types;
        std::vector<stt::StrongLiteral> literals;
        std::set<std::string> literalsDependency;
        std::map<std::string, stt::StrongType*> nameToType;
        std::map<stt::StrongType*, std::vector<stt::StrongType*>> dependencyGraph;
        std::map<std::string, std::vector<stt::StrongType>> dependencyList;
    };
}


#endif //STRONGTYPETOOL_STRONGTYPESET_H
