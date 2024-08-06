/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:22:07 by htouil            #+#    #+#             */
/*   Updated: 2024/08/06 03:50:51 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/PmergeMe.hpp"

template<typename T>
bool	is_sorted(T &container)
{
	typename T::iterator	it;

	for (it = container.begin(); it != container.end() - 1; it++)
	{
		if (*it > *(it + 1))
			return (false);
	}
	return (true);
}


int	main(int ac, char **av)
{
	deque	dq;
	vector	vec;
	if (ac <= 1)
	{
		std::cerr << RED << "Error" << std::endl << "too few arguments" << RESET << std::endl;
		return (1);
	}
	if (parse_input(av) == 1)
		return (1);
	get_numbers(av, dq, vec);
	if (is_sorted(dq))
	{
		std::cout << "The sequence is already sorted" << std::endl;
		return (0);
	}
	sort_n_display(dq, vec);
	return (0);
}
