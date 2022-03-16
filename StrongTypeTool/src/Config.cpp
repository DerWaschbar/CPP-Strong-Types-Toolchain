//
// Created by waschbar on 16.03.22.
//

#include "Config.h"

Config::Config(const Config::Builder &builder) {
    this->headerOnly = builder.headerOnly;
    this->sttRootPath = builder.sttRootPath;
}

Config::Builder *Config::Builder::makeHeaderOnly() {
    this->headerOnly = true;
    return this;
}

Config::Builder *Config::Builder::setRootPath(const std::string& rootPath) {
    this->sttRootPath = rootPath;
    return this;
}
