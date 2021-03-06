//
// Created by Beka Grdzelishvili (DerWaschbar) on 26.01.22.
//

#include "Generator.h"
#include <iostream>
#include <utility>

#include "Deserializer/YamlDeserializer.h"
#include "Serializer/CMakeListsSerializer.h"
#include "Serializer/CPPHSerializer.h"
#include "Serializer/CPPSerializer.h"
#include "Serializer/HeaderOnlySerializer.h"
#include "Serializer/LiteralHSerializer.h"
#include "Serializer/LiteralHeaderOnlySerializer.h"
#include "Serializer/LiteralSerializer.h"

Generator::Generator(const path& configPath, const Validator& validator) {
    if(!boost::filesystem::is_regular_file(absolute(configPath))) {
        assert(false);
    }

    this->configPath = configPath;
    this->rootPath = configPath.parent_path() / "StrongTypes";

    this->validator = validator;
}

bool Generator::generate(const GenerationConfig& config) {
    this->rootPath = config.getRootPath().value_or(configPath.parent_path()) / "StrongTypes";

    std::optional<stt::StrongTypeSet> oTypeSet = loadConfiguration();
    if(!oTypeSet.has_value()) {
        return false;
    }
    stt::StrongTypeSet typeSet = oTypeSet.value();

    if(config.validationEnabled()) {
        if(!validate(typeSet, config))
            return false;
    } else {
        std::cout << "Warning: Validation is not enabled.\n";
    }

    boost::filesystem::create_directories(this->rootPath);

    generateCMakeLists(typeSet, config);

    for(const stt::StrongType& type : typeSet.getTypes()) {
        generateStrongType(type, typeSet.getDependencies(type), config);
    }

    if(typeSet.hasLiterals()) {
        generateStrongLiterals(typeSet, config);
    }

    return true;
}

std::optional<stt::StrongTypeSet> Generator::loadConfiguration() {
    try {
        if(this->deserializer.has_value())
            return this->deserializer.value()->deserialize(configPath.string());
        return YamlDeserializer().deserialize(configPath.string());
    } catch (...) {
        std::cerr << "Could not deserialize the configuration file.\n"
                  << "Try checking it against the schema with Yamale.\n";
        return {};
    }
}

bool Generator::generateStrongType(const stt::StrongType& type,
                                   const std::vector<stt::StrongType>& dependencyList,
                                   const GenerationConfig& config) {
    TemplateManager templateManager = config.getTemplatesPath().has_value()
                                              ? TemplateManager(config.getTemplatesPath().value())
                                              : TemplateManager();

    if(config.isHeaderOnly()) {
        HeaderOnlySerializer serializer(templateManager);
        const std::string headerFileName = type.getTypeName() + ".h";
        const std::string headerText = serializer.serializeStrongType(type, dependencyList);

        boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
    } else {
        CPPHSerializer cpphSerializer(templateManager);
        const std::string headerFileName = type.getTypeName() + ".h";
        const std::string headerText = cpphSerializer.serializeStrongType(type, dependencyList);

        CPPSerializer cppSerializer(templateManager);
        const std::string classFileName = type.getTypeName() + ".cpp";
        const std::string classText = cppSerializer.serializeStrongType(type);

        boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
        boost::filesystem::ofstream(this->rootPath / classFileName) << classText;
    }

    return true;
}

bool Generator::generateStrongLiterals(const stt::StrongTypeSet& strongTypeSet,
                                       const GenerationConfig& config) {
    TemplateManager templateManager = config.getTemplatesPath().has_value()
                                              ? TemplateManager(config.getTemplatesPath().value())
                                              : TemplateManager();

    if(config.isHeaderOnly()) {
        LiteralHeaderOnlySerializer serializer(templateManager);
        const std::string headerFileName = "StrongLiterals.h";
        const std::string headerText = serializer.serialize(strongTypeSet)[0];

        boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
    } else {
        LiteralHSerializer hSerializer(templateManager);
        const std::string headerFileName = "StrongLiterals.h";
        const std::string headerText = hSerializer.serialize(strongTypeSet)[0];

        LiteralSerializer serializer(templateManager);
        const std::string classFileName = "StrongLiterals.cpp";
        const std::string classText = serializer.serialize(strongTypeSet)[0];

        boost::filesystem::ofstream(this->rootPath / headerFileName) << headerText;
        boost::filesystem::ofstream(this->rootPath / classFileName) << classText;
    }
    return true;
}

bool Generator::generateCMakeLists(const stt::StrongTypeSet& strongTypeSet,
                                   const GenerationConfig& config) {
    CMakeListsSerializer cMakeListSerializer;
    const std::string cmake = cMakeListSerializer.serialize(strongTypeSet, config.isHeaderOnly());

    boost::filesystem::ofstream(this->rootPath / "CMakeLists.txt") << cmake;

    return true;
}

bool Generator::validate(const stt::StrongTypeSet& strongTypeSet, const GenerationConfig& config) {
    std::vector<ValidationResult> result = this->validator.validate(strongTypeSet);
    if(result.empty()) {
        std::cout << "YAML configuration satisfies all validation rules.\n";
        return true;
    } else {
        std::cerr << "YAML configuration violates part or all of the validation rules.\n";

        path vout = config.getValidationOutPath().value_or(boost::filesystem::current_path() /
                                                           "stgenerator-validation-output.txt");
        boost::filesystem::ofstream ofs(vout);

        ofs << "STGenerator Validation Result\n\n";
        ofs << "Violations:\n";
        for(const ValidationResult& r : result) {
            ofs << "- " << (r.isError() ? "Error: " : "Warning: ") << r.getResult() << "\n";
        }

        std::cout << "Validation output is written in " << absolute(vout).string() << "\n";
        return false;
    }
}
