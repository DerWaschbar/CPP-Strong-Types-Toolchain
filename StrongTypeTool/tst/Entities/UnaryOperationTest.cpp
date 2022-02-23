//
// Created by waschbar on 13.02.22.
//

#include <gtest/gtest.h>

#include "Entities/UnaryOperation.h"

TEST(UnaryOperation, get)
{
    stt::UnaryOperation op("+", "float");

    EXPECT_EQ(op.getOperation(), "+");
}

TEST(UnaryOperation, getResType)
{
    stt::UnaryOperation op("+", "float");

    EXPECT_EQ(op.getResType(), "float");
}