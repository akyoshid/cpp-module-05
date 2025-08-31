/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:42:46 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 14:52:25 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), target_(src.target_){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& src) {
    if (this != &src) {
        AForm::operator=(src);
        target_ = src.target_;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkExecutable(executor);
    std::string ofn = target_ + "_shrubbery";
    std::ofstream ofs(ofn.c_str());
    if (!ofs.is_open())
        throw std::runtime_error("can't open output file: " + ofn);
    ofs << "      /\\      " << std::endl;
    ofs << "     /\\*\\     " << std::endl;
    ofs << "    /\\O\\*\\    " << std::endl;
    ofs << "   /*/\\/\\/\\   " << std::endl;
    ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
    ofs << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    ofs << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs.close();
}
