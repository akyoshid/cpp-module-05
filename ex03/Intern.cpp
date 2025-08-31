/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:35:37 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 17:15:32 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const Intern::makeFormTableItem Intern::makeFormTable_[3] = {
    {"shrubbery creation", &Intern::makeShrubberyCreationForm},
    {"robotomy request", &Intern::makeRobotomyRequestForm},
    {"presidential pardon", &Intern::makePresidentialPardonForm}
};

Intern::Intern() {
}

Intern::~Intern() {
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(
    const std::string& name, const std::string& target) const {
    for (int i = 0; i < 3; ++i) {
        if (makeFormTable_[i].name_ == name) {
            AForm *ret = (this->*(makeFormTable_[i].func_))(target);
            std::cout << "Intern creates " << name << std::endl;
            return ret;
        }
    }
    std::cout << "Intern couldn’t create " << name << std::endl;
    return NULL;
}
