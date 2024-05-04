/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:25:09 by htouil            #+#    #+#             */
/*   Updated: 2024/05/04 15:51:54 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		try
		{
			Bureaucrat				a("hatim", 1);
			ShrubberyCreationForm	b("khaymtkoum");

			a.signForm(b);
			a.executeForm(b);
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
	{
		std::cout << YELLOW << "------TEST 2------" << RESET << std::endl;
		try
		{
			Bureaucrat				a("hatim", 1);
			RobotomyRequestForm		b("khaymtkoum");

			a.signForm(b);
			a.executeForm(b);
			a.executeForm(b);
			a.executeForm(b);
			a.executeForm(b);
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