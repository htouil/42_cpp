/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:37:21 by htouil            #+#    #+#             */
/*   Updated: 2024/06/13 03:34:23 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span/Span.hpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		try
		{
			Span								a(5);
			std::vector<int>::const_iterator	it;

			a.addNumber(2);
			a.addNumber(5);
			a.addNumber(3);
			a.addNumber(4);
			a.addNumber(1);
			for (it = a.getCntr().begin(); it != a.getCntr().end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Found exception: " << RESET << e.what() << RESET << std::endl;
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
			Span								a(10);
			std::vector<int>::const_iterator	it;

			a.addMultiNumbers(10);
			for (it = a.getCntr().begin(); it != a.getCntr().end(); it++)
					std::cout << *it << " ";
			std::cout << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Found exception: " << RESET << e.what() << RESET << std::endl;
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
			Span								a(5);
			std::vector<int>::const_iterator	it;

			a.addMultiNumbers(5);
			for (it = a.getCntr().begin(); it != a.getCntr().end(); it++)
					std::cout << *it << " ";
			std::cout << std::endl;
			std::cout << BLUE << "Shortest span: " << RESET << a.shortestSpan() << std::endl;
			std::cout << GREEN << "Longest span: " << RESET << a.longestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << "Found exception: " << RESET << e.what() << RESET << std::endl;
		}
		
	}
	return (0);
}