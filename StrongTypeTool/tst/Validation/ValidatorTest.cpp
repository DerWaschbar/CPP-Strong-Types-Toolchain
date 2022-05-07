//
// Created by waschbar on 5/8/22.
//

#include <gtest/gtest.h>

#include "Validation/Validator.h"

TEST(Validator, getRules) {
    BinaryAssignmentTypeRule rule;
    Validator v({&rule});
    ASSERT_EQ(v.getRules().size(), 1);
}

TEST(Validator, addRule) {
    BinaryAssignmentTypeRule rule;
    LiteralsArgTypeRule newRule;

    Validator v({&rule});
    ASSERT_EQ(v.getRules().size(), 1);

    v.addRule(&newRule);
    ASSERT_EQ(v.getRules().size(), 2);
}

TEST(Validator, validate_correct) {
    stt::StrongTypeSet set({stt::StrongType("ST", "int", {}, {})}, {});

    Validator v;
    ASSERT_TRUE(v.validate(set).empty());
}

TEST(Validator, validate_faulty) {
    stt::StrongTypeSet set({stt::StrongType("", "int", {}, {})}, {});

    Validator v;
    ASSERT_EQ(v.validate(set).size(), 1);
}