/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:30:20 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 08:58:34 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_FORM_HPP_
# define EX02_FORM_HPP_

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm {
 public:
    AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
    AForm(const AForm& src);
    AForm& operator=(const AForm& src);
    ~AForm();
    const std::string& getName() const;
    bool getSignedFlag() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    class GradeTooHighException : public std::runtime_error {
     public:
        GradeTooHighException();
    };
    class GradeTooLowException : public std::runtime_error {
     public:
        GradeTooLowException();
    };
    void beSigned(const Bureaucrat& b);
 private:
    const std::string name_;
    bool signedFlag_;
    const int gradeToSign_;
    const int gradeToExec_;
    AForm(); // = delete
};

std::ostream& operator<<(std::ostream& lhs, const AForm& rhs);

#endif
