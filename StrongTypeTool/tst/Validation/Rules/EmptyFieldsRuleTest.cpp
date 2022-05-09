//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/8/22.
//

#include <gtest/gtest.h>

#include "Validation/Rules/EmptyFieldsRule.h"

TEST(EmptyFieldsRule, validate_empty1) {
    stt::StrongTypeSet set({}, {});
    EmptyFieldsRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(EmptyFieldsRule, validate_correct) {
    stt::StrongTypeSet set({stt::StrongType("ST", "int", {}, {})}, {});
    EmptyFieldsRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(EmptyFieldsRule, validate_faulty) {
    stt::StrongTypeSet set({stt::StrongType("", "int", {}, {})}, {});
    EmptyFieldsRule rule;
    ASSERT_EQ(rule.validate(set).size(), 1);
}

TEST(EmptyFieldsRule, validate_all_faulty) {
    stt::StrongTypeSet set({stt::StrongType("", "", {stt::BinaryOperation("", "", "")},
                                            {stt::UnaryOperation("", "")})},
                           {stt::StrongLiteral("", "", "")});
    EmptyFieldsRule rule;
    ASSERT_EQ(rule.validate(set).size(), 10);
}