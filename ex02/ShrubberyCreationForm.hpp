/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:42:51 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 11:32:02 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP_
# define EX02_SHRUBBERYCREATIONFORM_HPP_

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const & executor) const;
 private:
    std::string target_;
    ShrubberyCreationForm(); // = delete
};

#endif
