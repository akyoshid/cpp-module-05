/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:32:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 17:47:01 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <memory>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int to_int(const std::string& s) {
    std::istringstream iss(s);
    int value;
    if (!(iss >> value) || !(iss.eof()))
        throw std::runtime_error("Invalid integer: " + s);
    return value;
}

void run_test(char* bureName, int bureGrade) {
    Bureaucrat b(bureName, bureGrade);
    std::cout << b << std::endl;
    Intern i;
    std::auto_ptr<AForm> f[4];
    f[0].reset(i.makeForm("shrubbery creation", "Takumi"));
    f[1].reset(i.makeForm("robotomy request", "Takeshita"));
    f[2].reset(i.makeForm("presidential pardon", "Goto"));
    f[3].reset(i.makeForm("land swindle", "Harrison"));
    for (int i = 0; i < 4; ++i) {
        if (f[i].get() != NULL) {
            std::cout << *(f[i]) << std::endl;
            b.signForm(*(f[i]));
            std::cout << *(f[i]) << std::endl;
            b.executeForm(*(f[i]));
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr
            << "Usage: ./a.out BureaucratName BureaucratGrade" << std::endl;
        return 1;
    }
    try {
        run_test(argv[1], to_int(argv[2]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
