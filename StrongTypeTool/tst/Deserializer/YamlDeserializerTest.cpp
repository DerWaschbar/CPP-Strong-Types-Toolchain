//
// Created by Beka Grdzelishvili (DerWaschbar) on 24.02.22.
//

#include <boost/filesystem.hpp>
#include <gtest/gtest.h>

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
        boost::filesystem::remove(filePath);
    }
    boost::filesystem::ofstream ofs(filePath);
    ofs << configData;
    ofs.close();

    stt::StrongTypeSet typeSet = YamlDeserializer().deserialize(filePath.string());
    ASSERT_EQ(typeSet.getTypes().size(), 2);
    ASSERT_EQ(typeSet.getTypes()[0].getTypeName(), "Distance");
    ASSERT_EQ(typeSet.getTypes()[0].getWraps(), "float");
    ASSERT_EQ(typeSet.getTypes()[1].getTypeName(), "Time");
    ASSERT_EQ(typeSet.getTypes()[1].getWraps(), "int");
}

TEST(YamlDeserializer, deserialize_large) {
    const std::string configData = "StrongTypes:\n"
                                   "\n"
                                   "  - TypeName: \"Distance\"\n"
                                   "    Wraps: \"float\"\n"
                                   "    BinaryOperations:\n"
                                   "      - Operation: \"/\"\n"
                                   "        ArgType: \"Time\"\n"
                                   "        ResType: \"Velocity\"\n"
                                   "\n"
                                   "  - TypeName: \"Time\"\n"
                                   "    Wraps: \"float\"\n"
                                   "\n"
                                   "  - TypeName: \"Speed\"\n"
                                   "    Wraps: \"int\"\n"
                                   "\n"
                                   "  - TypeName: \"Velocity\"\n"
                                   "    Wraps: \"float\"\n"
                                   "    BinaryOperations:\n"
                                   "      - Operation: \"+\"\n"
                                   "        ArgType: \"Velocity\"\n"
                                   "        ResType: \"Velocity\"\n"
                                   "      - Operation: \"+=\"\n"
                                   "        ArgType: \"Velocity\"\n"
                                   "        ResType: \"Velocity\"\n"
                                   "      - Operation: \"/\"\n"
                                   "        ArgType: \"float\"\n"
                                   "        ResType: \"Velocity\"\n"
                                   "    UnaryOperations:\n"
                                   "      - Operation: \"-\"\n"
                                   "        ResType: \"Velocity\"\n"
                                   "\n"
                                   "StrongLiterals:\n"
                                   "  - Suffix: \"_kmh\"\n"
                                   "    ArgType: \"unsigned long long\"\n"
                                   "    ResType: \"Speed\"";
    const std::string testFileName = "stt-test-config.yaml";
    const boost::filesystem::path filePath = boost::filesystem::current_path() / testFileName;

    if(boost::filesystem::exists(filePath)) {
        boost::filesystem::remove(filePath);
    }
    boost::filesystem::ofstream ofs(filePath);
    ofs << configData;
    ofs.close();

    stt::StrongTypeSet typeSet = YamlDeserializer().deserialize(filePath.string());
    ASSERT_EQ(typeSet.getTypes().size(), 4);
    ASSERT_EQ(typeSet.getLiterals().size(), 1);
}

TEST(YamlDeserializer, deserializeStrongType) {
    YAML::Node node;
    node["TypeName"] = "StrongType";
    node["Wraps"] = "int";

    stt::StrongType type = YamlDeserializer().deserializeStrongType(node);
    ASSERT_EQ(type.getTypeName(), "StrongType");
    ASSERT_EQ(type.getWraps(), "int");
}

TEST(YamlDeserializer, deserializeBinaryOperation) {
    YAML::Node node;
    node["Operation"] = "+";
    node["ArgType"] = "float";
    node["ResType"] = "int";

    stt::BinaryOperation op = YamlDeserializer().deserializeBinaryOperation(node);
    ASSERT_EQ(op.getOperation(), "+");
    ASSERT_EQ(op.getArgType(), "float");
    ASSERT_EQ(op.getResType(), "int");
}

TEST(YamlDeserializer, deserializeUnaryOperation) {
    YAML::Node node;
    node["Operation"] = "+";
    node["ResType"] = "int";

    stt::UnaryOperation op = YamlDeserializer().deserializeUnaryOperation(node);
    ASSERT_EQ(op.getOperation(), "+");
    ASSERT_EQ(op.getResType(), "int");
}

TEST(YamlDeserializer, deserializeStrongLiteral) {
    YAML::Node node;
    node["Suffix"] = "_tst";
    node["ResType"] = "ST";
    node["ArgType"] = "int";

    stt::StrongLiteral literal = YamlDeserializer().deserializeStrongLiteral(node);
    ASSERT_EQ(literal.getSuffix(), "_tst");
    ASSERT_EQ(literal.getResType(), "ST");
    ASSERT_EQ(literal.getArgType(), "int");
}