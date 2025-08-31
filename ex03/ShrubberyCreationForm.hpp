/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:42:51 by akyoshid          #+#    #+#             */
/*   Updated: 2025/08/31 15:36:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_SHRUBBERYCREATIONFORM_HPP_
# define EX03_SHRUBBERYCREATIONFORM_HPP_

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
