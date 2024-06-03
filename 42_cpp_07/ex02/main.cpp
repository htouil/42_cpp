/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:20:26 by htouil            #+#    #+#             */
/*   Updated: 2024/06/03 20:03:15 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		
		try
		{
			Array<int>	a;

			std::cout << "size of a: " << TURQUOISE << a.size() << RESET << std::endl;
			std::cout << GREY << a[0] << RESET << std::endl;
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
		try
		{
			Array<char>	b(4);
			unsigned int			i;
			unsigned int			n;

			n = b.size();
			std::cout << "size of b = " << TURQUOISE << n << RESET << std::endl;
			std::cout << "{";
			for (i = 0; i < n; i++)
			{
				std::cout << PURPLE << b[i] << RESET;
				if (i < n - 1)
					std::cout << ", ";
			}
			std::cout << "}" << std::endl;

			b[1] = 65;
			b[3] = 65;
			std::cout << "{";
			for (i = 0; i < n; i++)
			{
				std::cout << PURPLE << b[i] << RESET;
				if (i < n - 1)
					std::cout << ", ";
			}
			std::cout << "}" << std::endl;

			std::cout << b[-1] << std::endl;
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
		std::cout << YELLOW << "------TEST 3------" << RESET << std::endl;
		try
		{
			Array<int>				c(0);
			Array<int>				d;
			unsigned int			n;

			d = c;
			n = d.size();
			std::cout << "size of d = " << TURQUOISE << n << RESET << std::endl;
			std::cout << PURPLE << d[n] << RESET;
		}
		catch (std::exception const &e)
		{
			std::cout << RED << "Found exception: " << RESET << e.what() << std::endl;
		}
	}
	return (0);
}
