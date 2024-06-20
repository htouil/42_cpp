/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:37:21 by htouil            #+#    #+#             */
/*   Updated: 2024/06/20 19:53:05 by htouil           ###   ########.fr       */
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
			std::vector<int>::const_iterator	cit;

			a.addNumber(8);
			a.addNumber(5);
			a.addNumber(0);
			a.addNumber(12);
			a.addNumber(10);
			for (cit = a.getCntr().begin(); cit != a.getCntr().end(); cit++)
				std::cout << *cit << " ";
			std::cout << std::endl;
			std::cout << BLUE << "Shortest span: " << RESET << a.shortestSpan() << std::endl;
			std::cout << GREEN << "Longest span: " << RESET << a.longestSpan() << std::endl;
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
			std::vector<int>::const_iterator	cit;

			a.addMultiNumbers(10);
			for (cit = a.getCntr().begin(); cit != a.getCntr().end(); cit++)
					std::cout << *cit << " ";
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
			std::vector<int>::const_iterator	cit;

			a.addMultiNumbers(5);
			for (cit = a.getCntr().begin(); cit != a.getCntr().end(); cit++)
					std::cout << *cit << " ";
			std::cout << std::endl;
			std::cout << BLUE << "Shortest span: " << RESET << a.shortestSpan() << std::endl;
			std::cout << GREEN << "Longest span: " << RESET << a.longestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << RED << "Found exception: " << RESET << e.what() << RESET << std::endl;
		}
		
	}

	{
		std::cout << YELLOW << "------TEST 4------" << RESET << std::endl;

		try
		{
			Span								a(10000);
			std::vector<int>::const_iterator	cit;

			a.addMultiNumbers(10000);
			for (cit = a.getCntr().begin(); cit != a.getCntr().end(); cit++)
					std::cout << *cit << " ";
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
