//
// Created by waschbar on 5/7/22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"
#include "Serializer/LiteralHSerializer.h"

TEST(LiteralHSerializer, serialize) {
    stt::StrongType T1("TestType", "WT", {}, {});
    stt::StrongLiteral L1("_tst", "int", "T1");
    stt::StrongTypeSet typeSet({T1}, {L1});

    LiteralHSerializer serializer;

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
                       "T1 operator\"\"_tst(int value);\n"
                       "\n"
                       "\n"
                       "#endif //STRONGLITERALS_H");
}

TEST(LiteralHSerializer, serialize_Empty) {
    stt::StrongTypeSet typeSet({}, {});

    LiteralHSerializer serializer;

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


