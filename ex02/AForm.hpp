/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:30:20 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 15:43:32 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_AFORM_HPP_
# define EX02_AFORM_HPP_

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm {
 public:
    AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
    AForm(const AForm& src);
    AForm& operator=(const AForm& src);
    virtual ~AForm();
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
    class NotSignedException : public std::runtime_error {
     public:
        NotSignedException();
    };
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0;
    void checkExecutable(const Bureaucrat& b) const;
 private:
    const std::string name_;
    bool signedFlag_;
    const int gradeToSign_;
    const int gradeToExec_;
    AForm(); // = delete
};

std::ostream& operator<<(std::ostream& lhs, const AForm& rhs);

#endif
