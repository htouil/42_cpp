/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:57:45 by htouil            #+#    #+#             */
/*   Updated: 2024/04/26 23:57:49 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
# include <string>
# include "../AForm/AForm.hpp"
// # include "../Bureaucrat/Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
								ShrubberyCreationForm(const std::string target);
								ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);
								~ShrubberyCreationForm();

		void					execute() const;
};

#endif