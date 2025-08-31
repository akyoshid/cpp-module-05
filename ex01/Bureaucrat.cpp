/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:33:21 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 03:13:50 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name), grade_(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name_(src.name_), grade_(src.grade_) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if (this != &src)
        grade_ = src.grade_;
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string& Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::incrementGrade() {
    if (grade_ > 1)
        --grade_;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    if (grade_ < 150)
        ++grade_;
    else
        throw GradeTooLowException();
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("Bureaucrat: grade is too high") {
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("Bureaucrat: grade is too low") {
}

void Bureaucrat::signForm(Form& f) {
    try {
        f.beSigned(*this);
        std::cout << name_ << " signed " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << name_ << " couldn’t sign " << f.getName()
            << " because '" << e.what() << "'." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs) {
    lhs << rhs.getName()
        << ", bureaucrat grade " << rhs.getGrade() << ".";
    return lhs;
}
