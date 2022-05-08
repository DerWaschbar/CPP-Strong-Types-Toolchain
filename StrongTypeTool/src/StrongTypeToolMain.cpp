//
// Created by waschbar on 16.03.22.
//

#include <iostream>
#include <boost/program_options.hpp>
#include "GenerationConfig.h"
#include "Generator.h"

#include "Validation/Validator.h"

namespace po = boost::program_options;

po::options_description initDescription() {
    po::options_description description("Usage: STGenerator <config file> [options] \n Options");

    description.add_options()
            ("help,h", "Display this help message")
            ("validate", "Validate strong type configuration")
            ("skip-validation", "Generate without validating configuration")
            ("validation-output, vout", po::value<std::string>(), "Directory path for validation output")
            ("header-only", "Generated header only library")
            ("root-path", po::value<std::string>(), "Directory path for StrongTypes folder to be generated in")
            ("templates-path", po::value<std::string>(), "Path for Template directory")
            ("config-path", po::value<std::string>(), "Configuration file path")
            ;

    return description;
}

GenerationConfig::Builder getConfigBuilder(po::variables_map vm) {
    GenerationConfig::Builder builder = GenerationConfig::Builder();

    if(vm.count("header-only")) {
        builder.makeHeaderOnly();
    }

    if(vm.count("root-path")) {
        builder.setRootPath(vm["root-path"].as<std::string>());
    }

    if(vm.count("templates-path")) {
        builder.setTemplatesPath(vm["templates-path"].as<std::string>());
    }

    if(vm.count("skip-validation")) {
        builder.disableValidation();
    }

    if(vm.count("validation-output")) {
        builder.setValidationOutPath(vm["validation-output"].as<std::string>());
    }

    return builder;
}

void validate(const std::string& fileName) {
    Validator validator;
    std::vector<ValidationResult> results = validator.validate(fileName);

    if(results.empty()) {
        std::cout << "YAML configuration satisfies all validation rules.\n";
        return;
    }

    std::cout << "YAML configuration violates part or all of the validation rules: \n\n";
    for(const ValidationResult& result : results) {
        std::cout
            << (result.isError() ? "Error: " : "Warning: ")
            << result.getResult() << "\n\n";
    }
}

int main(int argc, char** argv) {
    po::options_description description = initDescription();

    po::positional_options_description posDescriptions;
    posDescriptions.add("config-path", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(description).positional(posDescriptions)
                .style(po::command_line_style::default_style |
                       po::command_line_style::allow_long_disguise)
                .run(), vm);
    po::notify(vm);

    if(vm.empty() || vm.count("help") || !vm.count("config-path")) {
        std::cout << description << std::endl;
        return 0;
    }

    if(vm.count("validate")) {
        validate(vm["config-path"].as<std::string>());
        return 0;
    }

    GenerationConfig::Builder configBuilder = getConfigBuilder(vm);
    Generator generator(vm["config-path"].as<std::string>());

    if(generator.generate(configBuilder.build())) {
        std::cout << "Strong types library was generated.\n"
                     "Update CMakeLists.txt to add library to the project.\n"
                     "\n"
                     "```\n"
                     "\tadd_subdirectory(StrongTypes)\n"
                     "\ttarget_link_libraries(<target_name> PUBLIC StrongTypes)\n"
                     "```\n";
    }
    else {
        std::cout << "Error: Can not generate strong types library!";
    }

}

