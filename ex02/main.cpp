/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:32:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 17:52:29 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int to_int(const std::string& s) {
    std::istringstream iss(s);
    int value;
    if (!(iss >> value) || !(iss.eof()))
        throw std::runtime_error("Invalid integer: " + s);
    return value;
}

void run_with_form(Bureaucrat& b, AForm& f) {
    std::cout << f << std::endl;
    b.signForm(f);
    std::cout << f << std::endl;
    b.executeForm(f);
}

void run_test(char* bureName, int bureGrade, char* formTarget, int formType) {
    Bureaucrat b(bureName, bureGrade);
    std::cout << b << std::endl;
    if (formType == 0) {
        ShrubberyCreationForm form(formTarget);
        run_with_form(b, form);
    } else if (formType == 1) {
        RobotomyRequestForm form(formTarget);
        run_with_form(b, form);
    } else {
        PresidentialPardonForm form(formTarget);
        run_with_form(b, form);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr
            << "Usage: ./a.out BureaucratName BureaucratGrade "
            << "FormTarget FormType" << std::endl
            << "FormType: [0]ShrubberyCreationForm, "
            << "[1]RobotomyRequestForm, [2]PresidentialPardonForm" << std::endl;
        return 1;
    }
    try {
        run_test(argv[1], to_int(argv[2]), argv[3], to_int(argv[4]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
