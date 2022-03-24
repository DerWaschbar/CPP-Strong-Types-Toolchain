//
// Created by waschbar on 16.03.22.
//

#ifndef STRONGTYPETOOL_GENERATIONCONFIG_H
#define STRONGTYPETOOL_GENERATIONCONFIG_H

#include <boost/filesystem.hpp>
#include <optional>

class GenerationConfig {
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
        std::optional<boost::filesystem::path> templatesPath = {};

        Builder* makeHeaderOnly();
        Builder* setRootPath(const std::string& path);
        Builder* setTemplatesPath(const std::string& path);
        GenerationConfig build() { return GenerationConfig(*this); }
    };
    explicit GenerationConfig(const Builder& builder);
};


#endif //STRONGTYPETOOL_GENERATIONCONFIG_H
