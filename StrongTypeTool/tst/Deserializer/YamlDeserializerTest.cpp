//
// Created by waschbar on 24.02.22.
//

#include <gtest/gtest.h>
#include <boost/filesystem.hpp>

#include "Deserializer/YamlDeserializer.h"

TEST(YamlDeserializer, deserialize) {
    const std::string configData = "StrongTypes:\n"
                                   "\n"
                                   "  - TypeName: \"Distance\"\n"
                                   "    Wraps: \"float\"\n"
                                   "\n"
                                   "  - TypeName: \"Time\"\n"
                                   "    Wraps: \"int\"";
    const std::string testFileName = "stt-test-config.yaml";
    const boost::filesystem::path filePath = boost::filesystem::current_path() / testFileName;

    if(boost::filesystem::exists(filePath)) {
        FAIL() << "Can not create the test file. File with the name " + testFileName + " already exists.";
    }
    else {
        boost::filesystem::ofstream ofs(filePath);
        ofs << configData;
        ofs.close();
    }

    stt::StrongTypeSet typeSet = YamlDeserializer::deserialize(filePath.string());
    ASSERT_EQ(typeSet.getTypes().size(), 2);
    ASSERT_EQ(typeSet.getTypes()[0].getTypeName(), "Distance");
    ASSERT_EQ(typeSet.getTypes()[0].getWraps(), "float");
    ASSERT_EQ(typeSet.getTypes()[1].getTypeName(), "Time");
    ASSERT_EQ(typeSet.getTypes()[1].getWraps(), "int");
}

TEST(YamlDeserializer, deserializeStrongType) {
    YAML::Node node;
    node["TypeName"] = "StrongType";
    node["Wraps"] = "int";

    stt::StrongType type = YamlDeserializer::deserializeStrongType(node);
    ASSERT_EQ(type.getTypeName(), "StrongType");
    ASSERT_EQ(type.getWraps(), "int");
    /// TODO: Check collections.
}

TEST(YamlDeserializer, deserializeBinaryOperation) {
    YAML::Node node;
    node["Operation"] = "+";
    node["ArgType"] = "float";
    node["ResType"] = "int";

    stt::BinaryOperation op = YamlDeserializer::deserializeBinaryOperation(node);
    ASSERT_EQ(op.getOperation(), "+");
    ASSERT_EQ(op.getArgType(), "float");
    ASSERT_EQ(op.getResType(), "int");
}

TEST(YamlDeserializer, deserializeUnaryOperation) {
    YAML::Node node;
    node["Operation"] = "+";
    node["ResType"] = "int";

    stt::UnaryOperation op = YamlDeserializer::deserializeUnaryOperation(node);
    ASSERT_EQ(op.getOperation(), "+");
    ASSERT_EQ(op.getResType(), "int");
}