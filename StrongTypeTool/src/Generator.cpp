//
// Created by waschbar on 26.01.22.
//

#include "Generator.h"

#include "Deserializer/YamlDeserializer.h"
#include "Serializer/CPPHSerializer.h"
#include "Serializer/CPPSerializer.h"
#include "Serializer/HeaderOnlySerializer.h"
#include "Serializer/CMakeListsSerializer.h"
#include "Serializer/LiteralHeaderOnlySerializer.h"
#include "Serializer/LiteralSerializer.h"
#include "Serializer/LiteralHSerializer.h"

Generator::Generator(const path& configPath) {
    if(!boost::filesystem::is_regular_file(absolute(configPath))) {
        assert(false);
    }

    this->configPath = configPath;
    this->rootPath = configPath.parent_path() / "StrongTypes";
}

bool Generator::generate(const GenerationConfig& config) {
    this->rootPath = config.getRootPath().value_or(configPath.parent_path()) / "StrongTypes";

    boost::filesystem::create_directories(this->rootPath);
    stt::StrongTypeSet typeSet = loadConfiguration();

    generateCMakeLists(typeSet, config.isHeaderOnly());

    for(const stt::StrongType& type : typeSet.getTypes()) {
        generateStrongType(type, typeSet.getDependencies(type), config.isHeaderOnly());
    }

    if(typeSet.hasLiterals()) {
        generateStrongLiterals(typeSet, config.isHeaderOnly());
    }

    return true;
}

stt::StrongTypeSet Generator::loadConfiguration() {
    return YamlDeserializer::deserialize(configPath.string());
}

bool Generator::generateStrongType(const stt::StrongType& type, const std::vector<stt::StrongType>& dependencyList, bool headerOnly) {
    if(headerOnly) {
        HeaderOnlySerializer serializer;
        const std::string headerFileName = type.getTypeName() + ".h";
        const std::string headerText = serializer.serializeStrongType(type, dependencyList);

        boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
    }
    else {
        CPPHSerializer cpphSerializer;
        const std::string headerFileName = type.getTypeName() + ".h";
        const std::string headerText = cpphSerializer.serializeStrongType(type, dependencyList);

        CPPSerializer cppSerializer;
        const std::string classFileName = type.getTypeName() + ".cpp";
        const std::string classText = cppSerializer.serializeStrongType(type);

        /// Here should be validation part

        boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
        boost::filesystem::ofstream(this->rootPath / classFileName) << classText;
    }

    return true;
}

bool Generator::generateStrongLiterals(const stt::StrongTypeSet& strongTypeSet, bool headerOnly) {
    if(headerOnly) {
        LiteralHeaderOnlySerializer serializer;
        const std::string headerFileName = "StrongLiterals.h";
        const std::string headerText = serializer.serialize(strongTypeSet)[0];

        boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
    }
    else {
        LiteralSerializer serializer;
        const std::string headerFileName = "StrongLiterals.h";
        const std::string headerText = serializer.serialize(strongTypeSet)[0];

        LiteralHSerializer hSerializer;
        const std::string classFileName = "StrongLiterals.cpp";
        const std::string classText = hSerializer.serialize(strongTypeSet)[0];

        boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
        boost::filesystem::ofstream(this->rootPath / classFileName) << classText;
    }
    return true;
}

bool Generator::generateCMakeLists(const stt::StrongTypeSet &strongTypeSet, bool headerOnly) {
    CMakeListsSerializer cMakeListSerializer;
    const std::string cmake = cMakeListSerializer.serialize(strongTypeSet, headerOnly);

    boost::filesystem::ofstream(this->rootPath / "CMakeLists.txt") << cmake;

    return true;
}

bool Generator::validate() {
    /// TODO: Implement validation
    assert(false);
}


