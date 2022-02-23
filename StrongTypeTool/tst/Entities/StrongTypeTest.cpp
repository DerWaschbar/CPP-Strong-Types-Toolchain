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

TEST(StrongType, getUnaryOperations) {
    stt::StrongType type("TT", "WT", {}, {});
    ASSERT_EQ(type.getUnaryOperations().size(), 0);
    /// TODO: Add non-empty collection check.
}

TEST(StrongType, getBinaryOperations) {
    stt::StrongType type("TT", "WT", {}, {});
    ASSERT_EQ(type.getBinaryOperations().size(), 0);
    /// TODO: Add non-empty collection check.
}