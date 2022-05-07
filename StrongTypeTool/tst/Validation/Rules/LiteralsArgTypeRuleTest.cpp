//
// Created by waschbar on 5/8/22.
//

#include <gtest/gtest.h>

#include "Validation/Rules/LiteralsArgTypeRule.h"

TEST(LiteralsArgTypeRule, validate_empty) {
    stt::StrongTypeSet set({}, {});
    LiteralsArgTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(LiteralsArgTypeRule, validate_correct1) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {}, {})},
            {stt::StrongLiteral("_tst", "unsigned long long", "ST")});
    LiteralsArgTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(LiteralsArgTypeRule, validate_correct2) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {}, {})},
            {stt::StrongLiteral("_tst", "char", "ST")});
    LiteralsArgTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(LiteralsArgTypeRule, validate_correct3) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {}, {})},
            {stt::StrongLiteral("_tst", "const char *", "ST")});
    LiteralsArgTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(LiteralsArgTypeRule, validate_correct4) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {}, {})},
            {stt::StrongLiteral("_tst", "wchar_t", "ST")});
    LiteralsArgTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(LiteralsArgTypeRule, validate_faulty1) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {}, {})},
            {stt::StrongLiteral("_tst", "int", "ST")});
    LiteralsArgTypeRule rule;
    ASSERT_EQ(rule.validate(set).size(), 1);
}

TEST(LiteralsArgTypeRule, validate_faulty2) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {}, {})},
            {stt::StrongLiteral("_tst", "notype", "ST")});
    LiteralsArgTypeRule rule;
    ASSERT_EQ(rule.validate(set).size(), 1);
}

