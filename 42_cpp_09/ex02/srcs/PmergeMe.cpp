/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:23:18 by htouil            #+#    #+#             */
/*   Updated: 2024/07/27 20:55:59 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::deque<int>	dq;
	if (ac <= 1)
	{
		std::cerr << RED << "Error" << std::endl << "too few arguments" << RESET << std::endl;
		return (1);
	}
	dq = get_numbers(av);
	return (0);
}