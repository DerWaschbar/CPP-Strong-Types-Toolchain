//
// Created by waschbar on 26.01.22.
//

#include "Generator.h"

#include "Deserializer/YamlDeserializer.h"
#include "Serializer/CPPHSerializer.h"
#include "Serializer/CPPSerializer.h"

Generator::Generator(const path& configPath) : Generator(configPath, configPath.parent_path()) {}

Generator::Generator(const path& configPath, const path& rootPath, bool isRootPathRelative) {
    if(!boost::filesystem::is_regular_file(configPath) || !boost::filesystem::is_directory(rootPath))
        assert(false);

    this->configPath = configPath;
    this->rootPath = rootPath / "StrongTypes";
}

bool Generator::generate() {
    boost::filesystem::create_directory(rootPath);

    std::vector<stt::StrongType> types = loadConfiguration();
    for(stt::StrongType type : types) {
        generateStrongType(type);
    }

    return true;
}

std::vector<stt::StrongType> Generator::loadConfiguration() {
    return YamlDeserializer::deserialize(configPath.string());
}

bool Generator::generateStrongType(stt::StrongType type) {
    CPPHSerializer cpphSerializer;
    const std::string headerFileName = type.getTypeName() + ".h";
    const std::string headerText = cpphSerializer.serializeStrongType(type);

    CPPSerializer cppSerializer;
    const std::string classFileName = type.getTypeName() + ".cpp";
    const std::string classText = cppSerializer.serializeStrongType(type);

    /// Here should be validation part

    boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
    boost::filesystem::ofstream(this->rootPath / classFileName) << classText;

    return true;
}

bool Generator::validate() {
    /// TODO: Implement validation
    assert(false);
}


