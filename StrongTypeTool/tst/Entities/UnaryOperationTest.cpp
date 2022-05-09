//
// Created by Beka Grdzelishvili (DerWaschbar) on 13.02.22.
//

#include <gtest/gtest.h>

#include "Entities/UnaryOperation.h"

TEST(UnaryOperation, getOperation) {
    stt::UnaryOperation op("+", "float");
    EXPECT_EQ(op.getOperation(), "+");
}

TEST(UnaryOperation, getResType) {
    stt::UnaryOperation op("+", "float");
    EXPECT_EQ(op.getResType(), "float");
}