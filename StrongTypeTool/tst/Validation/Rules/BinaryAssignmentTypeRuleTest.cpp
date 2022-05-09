//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/8/22.
//

#include <gtest/gtest.h>

#include "Validation/Rules/BinaryAssignmentTypeRule.h"

TEST(BinaryAssignmentTypeRule, validate_empty) {
    stt::StrongTypeSet set({}, {});
    BinaryAssignmentTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(BinaryAssignmentTypeRule, validate_correct) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {stt::BinaryOperation("+=", "int", "ST")}, {})}, {});
    BinaryAssignmentTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(BinaryAssignmentTypeRule, validate_notAssignment) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {stt::BinaryOperation("+", "int", "int")}, {})}, {});
    BinaryAssignmentTypeRule rule;
    ASSERT_TRUE(rule.validate(set).empty());
}

TEST(BinaryAssignmentTypeRule, validate_faulty) {
    stt::StrongTypeSet set(
            {stt::StrongType("ST", "int", {stt::BinaryOperation("+=", "int", "int")}, {})}, {});
    BinaryAssignmentTypeRule rule;
    ASSERT_EQ(rule.validate(set).size(), 1);
}