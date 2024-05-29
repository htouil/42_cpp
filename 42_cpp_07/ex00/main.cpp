/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:57:15 by htouil            #+#    #+#             */
/*   Updated: 2024/05/27 18:18:55 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << GREEN << a << RESET << ", b = " << GREEN << b << RESET << std::endl << std::endl;
		std::cout << "min( a, b ) = " << GREEN << ::min( a, b ) << RESET << std::endl;
		std::cout << "max( a, b ) = " << GREEN << ::max( a, b ) << RESET << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << YELLOW << "------TEST 2------" << RESET << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << BLUE << c << RESET << ", d = " << BLUE << d << RESET << std::endl << std::endl;
		std::cout << "min( c, d ) = " << BLUE << ::min( c, d ) << RESET << std::endl;
		std::cout << "max( c, d ) = " << BLUE << ::max( c, d ) << RESET << std::endl;
	}
	return (0);
}