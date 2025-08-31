/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:43:18 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 15:36:02 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_PRESIDENTIALPARDONFORM_HPP_
# define EX03_PRESIDENTIALPARDONFORM_HPP_

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const & executor) const;
 private:
    std::string target_;
    PresidentialPardonForm(); // = delete
};

#endif
