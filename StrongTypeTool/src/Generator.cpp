//
// Created by waschbar on 26.01.22.
//

#include "Generator.h"

#include "Deserializer/YamlDeserializer.h"
#include "Serializer/CPPHSerializer.h"
#include "Serializer/CPPSerializer.h"
#include "Serializer/HeaderOnlySerializer.h"
#include "Serializer/CMakeListsSerializer.h"

Generator::Generator(const path& configPath) : Generator(configPath, configPath.parent_path()) {}

Generator::Generator(const path& configPath, const path& rootPath, bool isRootPathRelative) {
    if(!boost::filesystem::is_regular_file(configPath) || !boost::filesystem::is_directory(rootPath))
        assert(false);

    this->configPath = configPath;
    this->rootPath = rootPath / "StrongTypes";
}

bool Generator::generate(bool headerOnly) {
    boost::filesystem::create_directory(rootPath);
    stt::StrongTypeSet typeSet = loadConfiguration();

    generateCMakeLists(typeSet, headerOnly);

    for(const stt::StrongType& type : typeSet.getTypes()) {
        generateStrongType(type, typeSet.getDependencies(type), headerOnly);
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


