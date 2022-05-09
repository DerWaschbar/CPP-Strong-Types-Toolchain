//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/7/22.
//

#include <gtest/gtest.h>

#include "Entities/StrongLiteral.h"

TEST(StrongLiteral, getSuffix) {
    stt::StrongLiteral literal("tst", "int", "TestST");
    EXPECT_EQ(literal.getSuffix(), "tst");
}

TEST(StrongLiteral, getResType) {
    stt::StrongLiteral literal("tst", "int", "TestST");
    EXPECT_EQ(literal.getResType(), "TestST");
}

TEST(StrongLiteral, getArgType) {
    stt::StrongLiteral literal("tst", "int", "TestST");
    EXPECT_EQ(literal.getArgType(), "int");
}