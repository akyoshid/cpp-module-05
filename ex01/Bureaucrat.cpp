/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:33:21 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/30 06:10:45 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name(src.name), grade(src.grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if (this != &src)
        grade = src.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade > 1)
        --grade;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    if (grade < 150)
        ++grade;
    else
        throw GradeTooLowException();

}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("Bureaucrat: grade is too high") {
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("Bureaucrat: grade is too low") {
}

std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs) {
    lhs << rhs.getName()
        << ", bureaucrat grade " << rhs.getGrade() << ".";
    return lhs;
}
