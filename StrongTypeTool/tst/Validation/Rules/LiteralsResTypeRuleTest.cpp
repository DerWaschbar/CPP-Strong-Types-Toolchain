//
// Created by waschbar on 5/8/22.
//

#include <gtest/gtest.h>

#include "Validation/Rules/LiteralsResTypeRule.h"

TEST(LiteralsResTypeRule, validate_empty) {
    stt::StrongTypeSet set({}, {});
    LiteralsResTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(LiteralsResTypeRule, validate_correct) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {}, {})},
            {stt::StrongLiteral("_tst", "unsigned long long", "ST")});
    LiteralsResTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(LiteralsResTypeRule, validate_faulty) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {}, {})},
            {stt::StrongLiteral("_tst", "unsigned long long", "SType")});
    LiteralsResTypeRule rule;
    ASSERT_EQ(rule.validate(set).size(), 1);
}
