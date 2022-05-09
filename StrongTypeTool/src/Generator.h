//
// Created by Beka Grdzelishvili (DerWaschbar) on 26.01.22.
//

#ifndef STRONGTYPETOOL_GENERATOR_H
#define STRONGTYPETOOL_GENERATOR_H


#include <boost/filesystem.hpp>

#include "Deserializer/YamlDeserializer.h"
#include "Entities/StrongTypeSet.h"
#include "GenerationConfig.h"
#include "Validation/Validator.h"

class Generator {
    using path = boost::filesystem::path;

public:
    explicit Generator(const path& configPath, const Validator& validator = Validator());
    bool generate(const GenerationConfig& config);
    void setDeserializer(Deserializer* otherDeserializer) {
        this->deserializer = otherDeserializer;
    }

private:
    stt::StrongTypeSet loadConfiguration();
    bool generateStrongType(const stt::StrongType& type,
                            const std::vector<stt::StrongType>& dependencyList,
                            const GenerationConfig& config);
    bool generateStrongLiterals(const stt::StrongTypeSet& strongTypeSet,
                                const GenerationConfig& config);
    bool generateCMakeLists(const stt::StrongTypeSet& strongTypeSet,
                            const GenerationConfig& config);
    bool validate(const stt::StrongTypeSet& strongTypeSet, const GenerationConfig& config);

private:
    path configPath;
    path rootPath;
    Validator validator;
    std::optional<Deserializer*> deserializer = {};
};


#endif//STRONGTYPETOOL_GENERATOR_H
