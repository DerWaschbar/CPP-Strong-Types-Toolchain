//
// Created by waschbar on 24.02.22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"

TEST(StrongTypeSet, getTypes) {
    stt::StrongTypeSet typeSet({
        stt::StrongType("T0", "WT", {}, {}),
        stt::StrongType("T1", "WT", {}, {}),
        stt::StrongType("T2", "WT", {}, {})
    });

    std::vector<stt::StrongType> types = typeSet.getTypes();
    ASSERT_EQ(types.size(), 3);
    /// TODO: Check collection contents.
}

/// TODO: Check dependencies.