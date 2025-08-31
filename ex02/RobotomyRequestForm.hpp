/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:43:20 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 11:37:31 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_ROBOTOMYREQUESTFORM_HPP_
# define EX02_ROBOTOMYREQUESTFORM_HPP_

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const & executor) const;
 private:
    std::string target_;
    RobotomyRequestForm(); // = delete
};

#endif
