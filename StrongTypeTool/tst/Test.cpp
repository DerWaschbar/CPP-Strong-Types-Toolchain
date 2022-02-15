//
// Created by waschbar on 13.02.22.
//

#include <gtest/gtest.h>
#include <string>

int main(int argc, char **argv) {

    std::string filePath = "/home/waschbar/Desktop/Workspace/Thesis/CPP-Strong-Types-Toolchain/StrongTypeTool/outTest/test.yaml";

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}