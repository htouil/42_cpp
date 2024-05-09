/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:25:09 by htouil            #+#    #+#             */
/*   Updated: 2024/05/09 18:16:08 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Intern/Intern.hpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		try
		{
			Intern		i;
			AForm		*f;
			Bureaucrat	b("hatim", 1);

			f = i.makeForm("Presidential Pardon", "Bender");
			if (!f)
				return (0);
			b.signForm(*f);
			b.executeForm(*f);
			delete f;
		}
		catch (std::exception const &e)
		{
			std::cerr << RED << "Found exception: " << RESET << e.what() << std::endl;
		}
	}
	
	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
