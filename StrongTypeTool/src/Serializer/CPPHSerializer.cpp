//
// Created by waschbar on 24.01.22.
//

#include "CPPHSerializer.h"

#include <nlohmann/json.hpp>
#include <inja/inja.hpp>
#include <boost/algorithm/string.hpp>

const std::string CPPH_HEADER = "//\n"
                           "// Created by program.\n"
                           "//\n"
                           "\n"
                           "#ifndef {{ NAME }}_H\n"
                           "#define {{ NAME }}_H\n"
                           "\n"
                           "\n"
                           "class {{ name }} {\n"
                           "public:\n"
                           "    using wrappedType = {{ wraps }};\n"
                           "\n"
                           "    explicit constexpr {{ name }}(wrappedType const& value) : wrappedValue(value) {}\n"
                           "    wrappedType constexpr get() const { return wrappedValue; }\n\n";
const std::string CPPH_FOOTER = "private:\n"
                               "    wrappedType wrappedValue;\n"
                               "};\n"
                               "\n"
                               "\n"
                               "#endif // {{ NAME }}_H";

std::vector<std::string> CPPHSerializer::serialize(const std::vector<stt::StrongType> &strongTypes) {
    std::vector<std::string> headers(strongTypes.size());
    for(const stt::StrongType& type : strongTypes) {
        headers.push_back(serializeStrongType(type));
    }
    return headers;
}

std::string CPPHSerializer::serializeStrongType(const stt::StrongType &strongType) {
    nlohmann::json type;
    type["name"] = strongType.getTypeName();
    type["NAME"] = boost::to_upper_copy<std::string>(strongType.getTypeName());
    type["wraps"] = strongType.getWraps();

    std::string header;
    header += inja::render(CPPH_HEADER, type);

    header += "public:\n";
    for(const stt::BinaryOperation &op : strongType.getBinaryOperations()) {
        header += serializeBinaryOperation(op);
    }
    header += "\n";

    for(const stt::UnaryOperation &op : strongType.getUnaryOperations()) {
        header += serializeUnaryOperation(op);
    }
    header += "\n";

    header += inja::render(CPPH_FOOTER, type);
    return header;
}

std::string CPPHSerializer::serializeBinaryOperation(const stt::BinaryOperation &binaryOperation) {
    nlohmann::json opJson;
    opJson["res"] = binaryOperation.getResType();
    opJson["arg"] = binaryOperation.getArgType();
    opJson["op"] = binaryOperation.getOperation();

    const std::string OP = "    " "{{ res }} operator{{ op }}(const {{ arg }} &other) const;" "\n";

    return inja::render(OP, opJson);
}

std::string CPPHSerializer::serializeUnaryOperation(const stt::UnaryOperation &unaryOperation) {
    /// TODO: Do this!
    return "// TODO: unary op";
}
