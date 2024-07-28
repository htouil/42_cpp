/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:22:07 by htouil            #+#    #+#             */
/*   Updated: 2024/07/28 20:10:51 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/PmergeMe.hpp"

int	main(int ac, char **av)
{
	deque	dq;
	if (ac <= 1)
	{
		std::cerr << RED << "Error" << std::endl << "too few arguments" << RESET << std::endl;
		return (1);
	}
	parse_input(av);
	dq = get_numbers(av);
	// unsigned int	i;
	// i = 0;
	// while (i < dq.size())
	// {
	// 	std::cout << dq[i] << " ";
	// 	i++;
	// }
	// std::cout << std::endl;
	return (0);
}
