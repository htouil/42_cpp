/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:20:26 by htouil            #+#    #+#             */
/*   Updated: 2024/06/01 20:30:48 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		Array<int>	a;
		
		std::cout << "size of a: " << TURQUOISE << a.size() << RESET << std::endl;
		try
		{
			std::cout << "element 1 of a: " << GREY << a.getArr()[0] << RESET << std::endl;
			std::cout << "SALAM" << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << RED << "Found exception: " << RESET << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << YELLOW << "------TEST 2------" << RESET << std::endl;
		Array<char>	b(5);
		char			*tmp;
		unsigned int			i;
		unsigned int			n;

		n = b.size();
		tmp = b.getArr();
		std::cout << "size of b = " << TURQUOISE << n << RESET << std::endl;
		std::cout << "{";
		for (i = 0; i < n; i++)
		{
			std::cout << GOLD << tmp[i] << RESET;
			if (i < 4)
				std::cout << ", ";
		}
		std::cout << "}" << std::endl;
	}
	return (0);
}
