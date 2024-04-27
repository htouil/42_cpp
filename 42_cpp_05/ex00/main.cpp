/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:13:16 by htouil            #+#    #+#             */
/*   Updated: 2024/04/25 17:01:13 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"

int	main()
{
	{
		// Bureaucrat	a;
		// Bureaucrat	b("hatim", 1);

		// std::cout << "a is " << a << std::endl;
		// std::cout << "b is " << b << std::endl;

		// std::cout << "--------------------------------------------------------------------------" << std::endl;

		// a.setName("lm9awed");
		// a.setGrade(2);

		// std::cout << "a is " << a << std::endl;
		// std::cout << "b is " << b << std::endl;
	}
	
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		try
		{
			Bureaucrat a;
			std::cout << "a is " << a << std::endl;
		}
		catch (std::exception const	&e)
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
			Bureaucrat	b("hatim", 1);
			std::cout << "b is " << b << std::endl;
			b.incrementGrade();
			std::cout << "b is " << b << std::endl;
		}
		catch (std::exception const	&e)
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
		std::cout << YELLOW << "------TEST 3------" << RESET << std::endl;
		try
		{
			Bureaucrat	c("hmmm", 0);
			std::cout << "c is " << c << std::endl;
		}
		catch (std::exception const	&e)
		{
			std::cerr << RED << "Found exception: " << RESET << e.what() << std::endl;
		}
	}
	return (0);
}