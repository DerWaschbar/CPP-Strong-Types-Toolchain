//
// Created by waschbar on 23.02.22.
//

#include <gtest/gtest.h>

#include "Entities/StrongType.h"

TEST(StrongType, getTypeName) {
    stt::StrongType type("TestType", "WrappedType", {}, {});
    ASSERT_EQ(type.getTypeName(), "TestType");
}

TEST(StrongType, getWraps) {
    stt::StrongType type("TestType", "WrappedType", {}, {});
    ASSERT_EQ(type.getWraps(), "WrappedType");
}

TEST(StrongType, getUnaryOperations_0e) {
    stt::StrongType type("TT", "WT", {}, {});
    ASSERT_EQ(type.getUnaryOperations().size(), 0);
}

TEST(StrongType, getUnaryOperations_1e) {
    stt::StrongType type("TT", "WT", {},
                         {stt::UnaryOperation("+", "int")});
    std::vector<stt::UnaryOperation> uOps = type.getUnaryOperations();
    ASSERT_EQ(uOps.size(), 1);
    ASSERT_EQ(uOps[0].getOperation(), "+");
    ASSERT_EQ(uOps[0].getResType(), "int");
}

TEST(StrongType, getBinaryOperations) {
    stt::StrongType type("TT", "WT", {}, {});
    ASSERT_EQ(type.getBinaryOperations().size(), 0);
}

TEST(StrongType, getBinaryOperations_1e) {
    stt::StrongType type("TT", "WT",
                         {stt::BinaryOperation("+", "int", "TT")},
                         {});
    std::vector<stt::BinaryOperation> bOps = type.getBinaryOperations();
    ASSERT_EQ(bOps.size(), 1);
    ASSERT_EQ(bOps[0].getOperation(), "+");
    ASSERT_EQ(bOps[0].getArgType(), "int");
    ASSERT_EQ(bOps[0].getResType(), "TT");
}