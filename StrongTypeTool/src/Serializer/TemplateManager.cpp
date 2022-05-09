//
// Created by Beka Grdzelishvili (DerWaschbar) on 10.02.22.
//

#include "TemplateManager.h"
#include <iostream>

boost::filesystem::path getFileName(Template aTemplate) {
    switch(aTemplate) {
        case Template::T_Class: return "T_Class.txt";
        case Template::T_ClassHeader: return "T_ClassH.txt";
        case Template::T_ClassHeaderOnly: return "T_ClassHOnly.txt";
        case Template::T_BinaryAssignmentOp: return "T_BinaryAssignmentOp.txt";
        case Template::T_BinaryAssignmentOpHeader: return "T_BinaryAssignmentOpH.txt";
        case Template::T_BinaryOp: return "T_BinaryOp.txt";
        case Template::T_BinaryOpHeader: return "T_BinaryOpH.txt";
        case Template::T_UnaryOp: return "T_UnaryOp.txt";
        case Template::T_UnaryOpHeader: return "T_UnaryOpH.txt";
        case Template::T_Include: return "T_Include.txt";
        case Template::T_Literal: return "T_Literal.txt";
        case Template::T_LiteralHeaderOnly:
        case Template::T_LiteralHeader: return "T_LiteralH.txt";
        case Template::T_LiteralOp: return "T_LiteralOp.txt";
        case Template::T_LiteralOpHeader: return "T_LiteralOpH.txt";
    }
}

std::string TemplateManager::getTemplate(Template aTemplate) const {
    const path fileName = getFileName(aTemplate);
    std::string templateString;
    try {
        boost::filesystem::load_string_file(absolute((templateDirPath / fileName)), templateString);
    } catch(...) {
        std::cerr << "Failed to retrieve a template file - " << fileName.string()
                  << " from template directory - " << templateDirPath.string() << std::endl;
        throw;
    }
    return templateString;
}