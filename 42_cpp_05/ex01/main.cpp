/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:10:43 by htouil            #+#    #+#             */
/*   Updated: 2024/04/25 17:38:22 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form/Form.hpp"
#include "Bureaucrat/Bureaucrat.hpp"

int main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		Form	a;
		Form	b("do w lma", 5, 2);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
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
			Form	a("kontrada", 0, 1);

			std::cout << a << std::endl;
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
		std::cout << YELLOW << "------TEST 3------" << RESET << std::endl;
		try
		{
			Bureaucrat	a("hatim", 10);
			Form		x("kontrada", 5, 1);

			a.signForm(x);
			while (a.getGrade() > 1)
				a.incrementGrade();
			a.signForm(x);
		}
		catch(std::exception& e)
		{
			std::cerr << RED << "Found exception: " << RESET << e.what() << std::endl;
		}
	}
	return (0);
}