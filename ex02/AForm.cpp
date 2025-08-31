/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:30:23 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 08:45:28 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec)
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

AForm::AForm(const AForm& src)
    : name_(src.name_), signedFlag_(src.signedFlag_),
        gradeToSign_(src.gradeToSign_),
        gradeToExec_(src.gradeToExec_) {
}

AForm& AForm::operator=(const AForm& src) {
    if (this != &src)
        signedFlag_ = src.signedFlag_;
    return *this;
}

AForm::~AForm() {
}

const std::string& AForm::getName() const {
    return name_;
}

bool AForm::getSignedFlag() const {
    return signedFlag_;
}

int AForm::getGradeToSign() const {
    return gradeToSign_;
}

int AForm::getGradeToExec() const {
    return gradeToExec_;
}

AForm::GradeTooHighException::GradeTooHighException()
    : std::runtime_error("AForm: grade is too high"){
}

AForm::GradeTooLowException::GradeTooLowException()
    : std::runtime_error("AForm: grade is too low"){
}

void AForm::beSigned(const Bureaucrat& b) {
    if (gradeToSign_ >= b.getGrade())
        signedFlag_ = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& lhs, const AForm& rhs) {
    lhs << rhs.getName()
        << ", signed " << std::boolalpha << rhs.getSignedFlag()
        << ", sign grade " << rhs.getGradeToSign()
        << ", exec grade " << rhs.getGradeToExec() << ".";
    return lhs;
}
