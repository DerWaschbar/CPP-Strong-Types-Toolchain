//
// Created by waschbar on 16.03.22.
//

#ifndef STRONGTYPETOOL_CONFIG_H
#define STRONGTYPETOOL_CONFIG_H

#include <boost/filesystem.hpp>
#include <optional>

class Config {
private:
    bool headerOnly;
    std::optional<boost::filesystem::path> sttRootPath{};
public:
    bool isHeaderOnly() const { return this->headerOnly; }
    std::optional<boost::filesystem::path> getRootPath() const { return this->sttRootPath; }
public:
    class Builder {
    public:
        bool headerOnly = false;
        std::optional<boost::filesystem::path> sttRootPath = {};

        Builder* makeHeaderOnly();
        Builder* setRootPath(const std::string& rootPath);
        Config build() { return Config(*this); }
    };
    explicit Config(const Builder& builder);
};


#endif //STRONGTYPETOOL_CONFIG_H
