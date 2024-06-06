/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:44:29 by htouil            #+#    #+#             */
/*   Updated: 2024/06/06 13:43:03 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	square(int &x)
{
	x = x * x;
}

void	UperLowerCase(char &l)
{
	if (std::isupper(l))
		l = l + 32;
	else if (std::islower(l))
		l = l - 32;
}

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		int	arr[5] = {1, 2, 3, 4, 5};
		int	i;

		::iter(arr, 5, square);
		std::cout << "The integers array after iteration: {";
		for (i = 0; i < 5; i++)
		{
			std::cout << GREEN << arr[i] << RESET;
			if (i < 4)
				std::cout << ", ";
		}
		std::cout << "}" << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << YELLOW << "------TEST 2------" << RESET << std::endl;
		char	name[6] = "hAtIm";
		int		i;

		::iter(name, 5, UperLowerCase);
		std::cout << "The integers array after iteration: \"";
		for(i = 0; i < 5; i++)
			std::cout << BLUE << name[i] << RESET;
		std::cout << "\"" << std::endl;
	}
	return (0);
}
