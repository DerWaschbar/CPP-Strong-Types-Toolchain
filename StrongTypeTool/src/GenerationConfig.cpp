//
// Created by waschbar on 16.03.22.
//

#include "GenerationConfig.h"

GenerationConfig::GenerationConfig(const GenerationConfig::Builder &builder) {
    this->headerOnly = builder.headerOnly;
    this->sttRootPath = builder.sttRootPath;
}

GenerationConfig::Builder *GenerationConfig::Builder::makeHeaderOnly() {
    this->headerOnly = true;
    return this;
}

GenerationConfig::Builder *GenerationConfig::Builder::setRootPath(const std::string& path) {
    this->sttRootPath = path;
    return this;
}

GenerationConfig::Builder *GenerationConfig::Builder::setTemplatesPath(const std::string &path) {
    this->templatesPath = path;
    return this;
}

GenerationConfig::Builder *GenerationConfig::Builder::setValidationOutPath(const std::string &path) {
    this->validationOut = path;
    return this;
}

GenerationConfig::Builder *GenerationConfig::Builder::enableValidation() {
    this->validate = true;
    return this;
}

GenerationConfig::Builder *GenerationConfig::Builder::disableValidation() {
    this->validate = false;
    return this;
}
