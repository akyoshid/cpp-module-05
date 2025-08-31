/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:35:39 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 16:54:44 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_INTERN_HPP_
# define EX03_INTERN_HPP_

# include <string>

class AForm;

class Intern {
 public:
    Intern();
    ~Intern();
    AForm* makeShrubberyCreationForm(const std::string& target) const;
    AForm* makeRobotomyRequestForm(const std::string& target) const;
    AForm* makePresidentialPardonForm(const std::string& target) const;
    AForm* makeForm(const std::string& name, const std::string& target) const;
 private:
    typedef struct {
        std::string name_;
        AForm* (Intern::*func_)(const std::string& target) const;
    } makeFormTableItem;
    const static makeFormTableItem makeFormTable_[3];
    Intern(const Intern& src); // = delete
    Intern& operator=(const Intern& src); // = delete
};

#endif
