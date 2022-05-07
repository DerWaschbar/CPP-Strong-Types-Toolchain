//
// Created by waschbar on 5/7/22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"
#include "Serializer/LiteralHeaderOnlySerializer.h"

TEST(LiteralHeaderOnlySerializer, serialize) {
    stt::StrongType T1("TestType", "WT", {}, {});
    stt::StrongLiteral L1("_tst", "int", "T1");
    stt::StrongTypeSet typeSet({T1}, {L1});

    LiteralHeaderOnlySerializer serializer;

    std::vector<std::string> data = serializer.serialize(typeSet);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0], "//\n"
                       "// Created by program.\n"
                       "//\n"
                       "\n"
                       "#ifndef STRONGLITERALS_H\n"
                       "#define STRONGLITERALS_H\n"
                       "\n"
                       "#include \"T1.h\"\n"
                       "\n"
                       "inline T1 operator\"\"_tst(int value) {\n"
                       "    return T1(value);\n"
                       "}\n"
                       "\n"
                       "\n"
                       "\n"
                       "#endif //STRONGLITERALS_H");
}

TEST(LiteralHeaderOnlySerializer, serialize_Empty) {
    stt::StrongTypeSet typeSet({}, {});

    LiteralHeaderOnlySerializer serializer;

    std::vector<std::string> data = serializer.serialize(typeSet);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0], "//\n"
                       "// Created by program.\n"
                       "//\n"
                       "\n"
                       "#ifndef STRONGLITERALS_H\n"
                       "#define STRONGLITERALS_H\n"
                       "\n"
                       "\n"
                       "\n"
                       "\n"
                       "#endif //STRONGLITERALS_H");
}


