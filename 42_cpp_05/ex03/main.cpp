/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:25:09 by htouil            #+#    #+#             */
/*   Updated: 2024/05/08 17:51:56 by htouil           ###   ########.fr       */
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

			f = i.makeForm("Robotomy Request", "Bender");
			b.signForm(*f);
			b.executeForm(*f);
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
}