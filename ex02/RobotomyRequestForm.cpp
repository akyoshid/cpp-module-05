/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:43:23 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 14:52:06 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), target_(src.target_){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& src) {
    if (this != &src) {
        AForm::operator=(src);
        target_ = src.target_;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkExecutable(executor);
    std::string mes = "Bzzzzzz... drilling noises...\n";
    for (int i = 0; mes[i] != '\0'; ++i) {
        std::cout << mes[i] << '\a' << std::flush;
        usleep(500000);
    }
    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << target_
            << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << target_ << "." << std::endl;
}
