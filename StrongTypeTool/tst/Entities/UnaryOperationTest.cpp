//
// Created by waschbar on 13.02.22.
//

#include <gtest/gtest.h>

#include "../../src/Entities/UnaryOperation.h"

TEST(UnaryOperation_test, get_operation)
{
    stt::UnaryOperation op("+", "float");

    EXPECT_EQ(op.getOperation(), "+");
}

TEST(UnaryOperation_test, get_res_type)
{
    stt::UnaryOperation op("+", "float");

    EXPECT_EQ(op.getResType(), "float");
}