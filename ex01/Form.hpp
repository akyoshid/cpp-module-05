/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:30:20 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 02:50:28 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FORM_HPP_
# define EX01_FORM_HPP_

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form {
 public:
    Form(const std::string& name, int grade_to_sign, int grade_to_execute);
    Form(const Form& src);
    Form& operator=(const Form& src);
    ~Form();
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
    Form(); // = delete
};

std::ostream& operator<<(std::ostream& lhs, const Form& rhs);

#endif
