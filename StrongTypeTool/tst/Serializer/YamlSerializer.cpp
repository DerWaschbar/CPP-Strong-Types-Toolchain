//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/7/22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"
#include "Serializer/YamlSerializer.h"

TEST(YamlSerializer, serialize) {
    stt::StrongType T1("TestType", "int", {}, {});
    stt::StrongTypeSet typeSet({T1}, {});

    YAML::Node node = YamlSerializer::serialize(typeSet);
    ASSERT_EQ(node["StrongTypes"][0]["TypeName"].as<std::string>(), T1.getTypeName());
    ASSERT_EQ(node["StrongTypes"][0]["Wraps"].as<std::string>(), T1.getWraps());
}

TEST(YamlSerializer, serializeStrongType) {
    stt::StrongType T1("TestType", "int", {}, {});

    YAML::Node node = YamlSerializer::serializeStrongType(T1);
    ASSERT_EQ(node["TypeName"].as<std::string>(), T1.getTypeName());
    ASSERT_EQ(node["Wraps"].as<std::string>(), T1.getWraps());
}

TEST(YamlSerializer, serializeBinaryOperation) {
    stt::BinaryOperation op("+", "int", "int");

    YAML::Node node = YamlSerializer::serializeBinaryOperation(op);
    ASSERT_EQ(node["Operation"].as<std::string>(), op.getOperation());
    ASSERT_EQ(node["ArgType"].as<std::string>(), op.getArgType());
    ASSERT_EQ(node["ResType"].as<std::string>(), op.getResType());
}

TEST(YamlSerializer, serializeUnaryOperation) {
    stt::UnaryOperation op("+", "int");

    YAML::Node node = YamlSerializer::serializeUnaryOperation(op);
    ASSERT_EQ(node["Operation"].as<std::string>(), op.getOperation());
    ASSERT_EQ(node["ResType"].as<std::string>(), op.getResType());
}
