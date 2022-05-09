//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/7/22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"
#include "Serializer/CMakeListsSerializer.h"

TEST(CMakeListsSerializer, serialize) {
    stt::StrongTypeSet typeSet({stt::StrongType("TestType", "WT", {}, {})});

    CMakeListsSerializer serializer;
    ASSERT_EQ(serializer.serialize(typeSet, false), "add_library(StrongTypes"
                                                    "\n\t\tTestType.cpp"
                                                    "\n\t\tTestType.h)");
}

TEST(CMakeListsSerializer, serialize_headerOnly) {
    stt::StrongTypeSet typeSet({stt::StrongType("TestType", "WT", {}, {})});

    CMakeListsSerializer serializer;
    ASSERT_EQ(serializer.serialize(typeSet, true), "add_library(StrongTypes INTERFACE"
                                                   "\n\t\tTestType.h)");
}

TEST(CMakeListsSerializer, serialize_literals) {
    stt::StrongTypeSet typeSet({stt::StrongType("TestType", "WT", {}, {})},
                               {stt::StrongLiteral("_tst", "int", "TestType")});

    CMakeListsSerializer serializer;
    ASSERT_EQ(serializer.serialize(typeSet, false), "add_library(StrongTypes"
                                                    "\n\t\tStrongLiterals.cpp"
                                                    "\n\t\tStrongLiterals.h"
                                                    "\n\t\tTestType.cpp"
                                                    "\n\t\tTestType.h)");
}

TEST(CMakeListsSerializer, serialize_literals_headersOnly) {
    stt::StrongTypeSet typeSet({stt::StrongType("TestType", "WT", {}, {})},
                               {stt::StrongLiteral("_tst", "int", "TestType")});

    CMakeListsSerializer serializer;
    ASSERT_EQ(serializer.serialize(typeSet, true), "add_library(StrongTypes INTERFACE"
                                                   "\n\t\tStrongLiterals.h"
                                                   "\n\t\tTestType.h)");
}
