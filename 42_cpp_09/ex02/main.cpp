/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:22:07 by htouil            #+#    #+#             */
/*   Updated: 2024/08/05 09:51:46 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/PmergeMe.hpp"

int	main(int ac, char **av)
{
	deque	dq;
	vector	vec;
	if (ac <= 1)
	{
		std::cerr << RED << "Error" << std::endl << "too few arguments" << RESET << std::endl;
		return (1);
	}
	parse_input(av);
	get_numbers(av, dq, vec);
	if (std::is_sorted(vec.begin(), vec.end()))
	{
		std::cout << "The sequence is already sorted" << std::endl;
		return (0);
	}
	sort_n_display(dq, vec);
	// unsigned int	i;
	// i = -1;
	// std::cout << "std::deque: ";
	// while (++i < dq.size())
	// 	std::cout << dq[i] << " ";
	// std::cout << std::endl;
	// i = -1;
	// std::cout << "std::vector: ";
	// while (++i < vec.size())
	// 	std::cout << vec[i] << " ";
	// std::cout << std::endl;
	return (0);
}
