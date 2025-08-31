/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:33:23 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 02:18:30 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_BUREAUCRAT_HPP_
# define EX01_BUREAUCRAT_HPP_

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat {
 public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& src);
    ~Bureaucrat();
    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    class GradeTooHighException : public std::runtime_error {
     public:
        GradeTooHighException();
    };
    class GradeTooLowException : public std::runtime_error {
     public:
        GradeTooLowException();
    };
 private:
    Bureaucrat(); // = delete;
    const std::string name_;
    int grade_;
};

std::ostream& operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif
