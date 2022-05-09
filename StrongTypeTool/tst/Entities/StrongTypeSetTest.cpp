//
// Created by Beka Grdzelishvili (DerWaschbar) on 24.02.22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"

TEST(StrongTypeSet, getTypes) {
    stt::StrongTypeSet typeSet({stt::StrongType("T0", "WT", {}, {}),
                                stt::StrongType("T1", "WT", {}, {}),
                                stt::StrongType("T2", "WT", {}, {})});

    ASSERT_EQ(typeSet.getTypes().size(), 3);
}

TEST(StrongTypeSet, getDependencies_1) {
    stt::StrongType T1 = stt::StrongType("T1", "WT", {}, {});
    stt::StrongType T2 = stt::StrongType("T2", "WT", {}, {stt::UnaryOperation("-", "T1")});

    stt::StrongTypeSet typeSet({T1, T2});

    std::vector<stt::StrongType> types = typeSet.getDependencies(T2);
    ASSERT_EQ(types.size(), 1);
    ASSERT_EQ(types[0].getTypeName(), T1.getTypeName());
}

TEST(StrongTypeSet, getDependencies_2) {
    stt::StrongType T1 = stt::StrongType("T0", "WT", {}, {});
    stt::StrongType T2 = stt::StrongType("T1", "WT", {}, {stt::UnaryOperation("-", "T1")});

    stt::StrongTypeSet typeSet({T1, T2});

    std::vector<stt::StrongType> types = typeSet.getDependencies(T1);
    ASSERT_EQ(types.size(), 0);
}

TEST(StrongTypeSet, hasLiterals_false) {
    stt::StrongTypeSet typeSet({stt::StrongType("ST", "WT", {}, {})});

    ASSERT_FALSE(typeSet.hasLiterals());
}

TEST(StrongTypeSet, hasLiterals_true) {
    stt::StrongTypeSet typeSet({stt::StrongType("ST", "WT", {}, {})},
                               {stt::StrongLiteral("_tst", "int", "ST")});

    ASSERT_TRUE(typeSet.hasLiterals());
}

TEST(StrongTypeSet, getLiteralsDependency) {
    stt::StrongTypeSet typeSet({stt::StrongType("ST", "WT", {}, {})},
                               {stt::StrongLiteral("_tst", "int", "ST")});

    std::set<std::string> types = typeSet.getLiteralsDependency();
    ASSERT_EQ(types.size(), 1);
    ASSERT_EQ(types.count("ST"), 1);
}
