//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/8/22.
//

#include <gtest/gtest.h>

#include "Validation/ValidationResult.h"

TEST(ValidationResult, getResult) {
    ValidationResult result("text", ValidationResultType::Warning);
    ASSERT_EQ(result.getResult(), "text");
}

TEST(ValidationResult, getType) {
    ValidationResult result("text", ValidationResultType::Warning);
    ASSERT_TRUE(result.getType() == ValidationResultType::Warning);
}

TEST(ValidationResult, isWarning_true) {
    ValidationResult result("text", ValidationResultType::Warning);
    ASSERT_TRUE(result.isWarning());
}

TEST(ValidationResult, isWarning_false) {
    ValidationResult result("text", ValidationResultType::Error);
    ASSERT_FALSE(result.isWarning());
}

TEST(ValidationResult, isError_true) {
    ValidationResult result("text", ValidationResultType::Error);
    ASSERT_TRUE(result.isError());
}

TEST(ValidationResult, isError_false) {
    ValidationResult result("text", ValidationResultType::Warning);
    ASSERT_FALSE(result.isError());
}
