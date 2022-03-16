#include <iostream>
#include <fstream>

#include "yaml-cpp/yaml.h"
#include <nlohmann/json.hpp>
#include <boost/filesystem.hpp>
#include "inja/inja.hpp"
#include <gtest/gtest.h>

using json = nlohmann::json;

#include "src/Serializer/CPPHSerializer.h"
#include "src/Serializer/CPPSerializer.h"
#include "src/Generator.h"
#include "src/Serializer/TemplateManager.h"
#include "src/Deserializer/YamlDeserializer.h"
#include "src/Config.h"


using namespace boost::filesystem;

void test();
void testGeneration(std::string filePath);
void testSerialization(std::string filePath);


int main(int argc, char **argv) {
    std::string filePath = "/home/waschbar/Desktop/Workspace/Thesis/CPP-Strong-Types-Toolchain/StrongTypeTool/outTest/test.yaml";

    if(argc >= 2) {
        filePath = "/home/waschbar/Desktop/Workspace/Thesis/CPP-Strong-Types-Toolchain/StrongTypeTool/sys_tests/AverageVelocity/StrongTypes.yaml";
        filePath = argv[1];
    }

    Config config = Config::Builder().makeHeaderOnly()->build();

    Generator gen(filePath);
    gen.generate(Config::Builder()
        .setRootPath("/home/waschbar/Desktop/Workspace/Thesis/CPP-Strong-Types-Toolchain/StrongTypeTool/outTest/stt")
        ->build());

    std::cout << "OK" << std::endl;

    return 0;
}

void test() {
    std::cout << current_path().parent_path() << std::endl;
    path pth = current_path();

    file_status st = status(pth);
    if(is_directory(st)) {
        path dirPath = pth / "StrongTypes";
        create_directory(dirPath);
        ofstream ofs(dirPath / "Velocity.h");
        ofs << "Hello";
    }

}

void testGeneration(std::string filePath) {
    Generator gen(filePath);
    gen.generate(Config::Builder().build());
}

void testSerialization(std::string filePath) {
    stt::StrongTypeSet typeSet = YamlDeserializer::deserialize(filePath);
    stt::StrongType type = typeSet.getTypes()[0];

    CPPSerializer s;
    std::cout << s.serialize(typeSet)[2];
}