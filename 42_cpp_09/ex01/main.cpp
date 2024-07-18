/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:24:18 by htouil            #+#    #+#             */
/*   Updated: 2024/07/18 01:44:54 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		vector	vec;
		vector::iterator	it;
		vec = get_experssion(av[1]);
		// for (it = vec.begin(); it != vec.end(); it++)
		// 	std::cout << *it;
		// std::cout << std::endl;
		parse_calculate_expression(vec);
	}
	else
	{
		std::cerr << RED <<  "Error\n" << std::endl << "Wrong number of arguments!" << RESET << std::endl;
		return (1);
	}
	return (0);
}
