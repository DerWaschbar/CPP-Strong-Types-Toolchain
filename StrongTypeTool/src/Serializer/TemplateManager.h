//
// Created by waschbar on 10.02.22.
//

#ifndef STRONGTYPETOOL_TEMPLATEMANAGER_H
#define STRONGTYPETOOL_TEMPLATEMANAGER_H

#include <boost/filesystem.hpp>
#include <string>
#include <utility>

enum class Template {
    T_Class,
    T_ClassHeader,
    T_ClassHeaderOnly,
    T_BinaryOp,
    T_BinaryOpHeader,
    T_UnaryOp,
    T_UnaryOpHeader,
    T_BinaryAssignmentOp,
    T_BinaryAssignmentOpHeader,
    T_Include
};

class TemplateManager {
    using path = boost::filesystem::path;
public:
    explicit TemplateManager(path  templateDirPath) : templateDirPath(std::move(templateDirPath)) {}
    TemplateManager() : TemplateManager("src/Templates") {}

    virtual std::string getTemplate(Template aTemplate) const;

public:
    const path templateDirPath;
};


#endif //STRONGTYPETOOL_TEMPLATEMANAGER_H
