//
// Created by waschbar on 26.01.22.
//

#include "CPPSerializer.h"

#include <nlohmann/json.hpp>
#include <inja/inja.hpp>
#include <boost/algorithm/string.hpp>

const std::string CPP_HEADER= "//\n"
                               "// Created by program.\n"
                               "//\n"
                               "\n"
                               "#include \"{{ name }}.h\"\n\n";

std::vector<std::string> CPPSerializer::serialize(const std::vector<stt::StrongType> &strongTypes) {
    std::vector<std::string> classes(strongTypes.size());
    for(const stt::StrongType& type : strongTypes) {
        classes.push_back(serializeStrongType(type));
    }
    return classes;
}

std::string CPPSerializer::serializeStrongType(const stt::StrongType &strongType) {
    nlohmann::json type;
    type["name"] = strongType.getTypeName();
    type["NAME"] = boost::to_upper_copy<std::string>(strongType.getTypeName());
    type["wraps"] = strongType.getWraps();

    std::string cppCode;
    cppCode += inja::render(CPP_HEADER, type);

    for(const stt::BinaryOperation &op : strongType.getBinaryOperations()) {
        cppCode += inja::render(serializeBinaryOperation(op), type);
        cppCode += "\n";
    }

    for(const stt::UnaryOperation &op : strongType.getUnaryOperations()) {
        cppCode += inja::render(serializeUnaryOperation(op), type);
        cppCode += "\n";
    }

    return cppCode;
}

std::string CPPSerializer::serializeBinaryOperation(const stt::BinaryOperation &binaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = binaryOperation.getResType();
    opJson["arg"] = binaryOperation.getArgType();
    opJson["op"] = binaryOperation.getOperation();
    opJson["name"] = "{{ name }}";

    const std::string OP_SIG = "{{ res }} {{ name }}::operator{{ op }}(const {{ arg }} &other) const";

    std::string binOp =
            inja::render(OP_SIG, opJson) + "{\n"
            "   return {};\n"
            "}\n";

    return binOp;
}

std::string CPPSerializer::serializeUnaryOperation(const stt::UnaryOperation &unaryOperation) {
    /// TODO: Do this!
    return "// TODO: unary op";
}
