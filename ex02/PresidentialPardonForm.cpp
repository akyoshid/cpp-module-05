/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:43:13 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 14:51:47 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target_(target) {
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& src)
    : AForm(src), target_(src.target_){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& src) {
    if (this != &src) {
        AForm::operator=(src);
        target_ = src.target_;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkExecutable(executor);
    std::cout << target_
        << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
