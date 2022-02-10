//
// Created by waschbar on 10.02.22.
//

#include <iostream>
#include "TemplateManager.h"

boost::filesystem::path getFileName(Template aTemplate) {
    switch(aTemplate) {
        case Template::T_Class: return "T_Class.txt";
        case Template::T_ClassHeader: return "T_ClassH.txt";
        case Template::T_BinaryAssignmentOp: return "T_BinaryAssignmentOp.txt";
        case Template::T_BinaryAssignmentOpHeader: return "T_BinaryAssignmentOpH.txt";
        case Template::T_BinaryOp: return "T_BinaryOp.txt";
        case Template::T_BinaryOpHeader: return "T_BinaryOpH.txt";
        case Template::T_UnaryOp: return "T_UnaryOp.txt";
        case Template::T_UnaryOpHeader: return "T_UnaryOpH.txt";
    }
}

std::string TemplateManager::getTemplate(Template aTemplate) const {
    const path fileName = getFileName(aTemplate);
    std::string templateString;
    boost::filesystem::load_string_file(absolute((".." / templateDirPath / fileName)), templateString);
    return templateString;
}