//
// Created by Beka Grdzelishvili (DerWaschbar) on 16.03.22.
//

#ifndef STRONGTYPETOOL_GENERATIONCONFIG_H
#define STRONGTYPETOOL_GENERATIONCONFIG_H

#include <boost/filesystem.hpp>
#include <optional>

class GenerationConfig {
private:
    bool headerOnly;
    bool validate;
    std::optional<boost::filesystem::path> sttRootPath;
    std::optional<boost::filesystem::path> templatesPath;
    std::optional<boost::filesystem::path> validationOut;

public:
    bool isHeaderOnly() const { return this->headerOnly; }
    bool validationEnabled() const { return this->validate; }
    std::optional<boost::filesystem::path> getRootPath() const { return this->sttRootPath; }
    std::optional<boost::filesystem::path> getTemplatesPath() const { return this->templatesPath; }
    std::optional<boost::filesystem::path> getValidationOutPath() const { return this->validationOut; }

public:
    class Builder {
    public:
        bool headerOnly = false;
        bool validate = true;
        std::optional<boost::filesystem::path> sttRootPath;
        std::optional<boost::filesystem::path> templatesPath;
        std::optional<boost::filesystem::path> validationOut;

        Builder* makeHeaderOnly();
        Builder* setRootPath(const std::string& path);
        Builder* setTemplatesPath(const std::string& path);
        Builder* setValidationOutPath(const std::string& path);
        Builder* enableValidation();
        Builder* disableValidation();
        GenerationConfig build() { return GenerationConfig(*this); }
    };
    explicit GenerationConfig(const Builder& builder);
};


#endif//STRONGTYPETOOL_GENERATIONCONFIG_H
