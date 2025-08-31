/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:30:23 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 03:11:02 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
    : name_(name), signedFlag_(false),
        gradeToSign_(gradeToSign), gradeToExec_(gradeToExec) {
    if (gradeToSign_ < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign_ > 150) {
        throw GradeTooLowException();
    }
    if (gradeToExec_ < 1) {
        throw GradeTooHighException();
    } else if (gradeToExec_ > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& src)
    : name_(src.name_), signedFlag_(src.signedFlag_),
        gradeToSign_(src.gradeToSign_),
        gradeToExec_(src.gradeToExec_) {
}

Form& Form::operator=(const Form& src) {
    if (this != &src)
        signedFlag_ = src.signedFlag_;
    return *this;
}

Form::~Form() {
}

const std::string& Form::getName() const {
    return name_;
}

bool Form::getSignedFlag() const {
    return signedFlag_;
}

int Form::getGradeToSign() const {
    return gradeToSign_;
}

int Form::getGradeToExec() const {
    return gradeToExec_;
}

Form::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("Form: grade is too high"){
}

Form::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("Form: grade is too low"){
}

void Form::beSigned(const Bureaucrat& b) {
    if (gradeToSign_ >= b.getGrade())
        signedFlag_ = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& lhs, const Form& rhs) {
    lhs << rhs.getName()
        << ", signed " << std::boolalpha << rhs.getSignedFlag()
        << ", sign grade " << rhs.getGradeToSign()
        << ", exec grade " << rhs.getGradeToExec() << ".";
    return lhs;
}
