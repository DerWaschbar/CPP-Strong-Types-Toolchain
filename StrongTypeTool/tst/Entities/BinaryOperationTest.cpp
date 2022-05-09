//
// Created by Beka Grdzelishvili (DerWaschbar) on 23.02.22.
//

#include <gtest/gtest.h>

#include "Entities/BinaryOperation.h"

TEST(BinaryOperation, getOperation) {
    stt::BinaryOperation op("+", "int", "float");
    EXPECT_EQ(op.getOperation(), "+");
}

TEST(BinaryOperation, getResType) {
    stt::BinaryOperation op("+", "int", "float");
    EXPECT_EQ(op.getResType(), "float");
}

TEST(BinaryOperation, getArgType) {
    stt::BinaryOperation op("+", "int", "float");
    EXPECT_EQ(op.getArgType(), "int");
}

TEST(BinaryOperation, validBinaryAssignment) {
    for(std::string binOp : {"+=", "/=", "*=", "-=", "%=", "&=", "|=", "^=", "<<=", ">>="}) {
        stt::BinaryOperation op(binOp, "int", "float");
        EXPECT_TRUE(op.isBinaryAssignment());
    }
}

TEST(BinaryOperation, invalidBinaryAssignment) {
    for(std::string binOp : {"++", "+", "==", "<<", "*"}) {
        stt::BinaryOperation op(binOp, "int", "float");
        EXPECT_FALSE(op.isBinaryAssignment());
    }
}