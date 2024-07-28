/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:23:18 by htouil            #+#    #+#             */
/*   Updated: 2024/07/28 19:36:58 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	parse_input(char **av)
{
	int			i;
	long int	lg;
	char		*endptr;

	i = 1;
	errno = 0;
	while (av[i])
	{
		lg = std::strtol(av[i], &endptr, 10);
		// std::cout << lg << std::endl;
		// std::cout << errno << std::endl;
		// std::cout << *endptr << std::endl;
		if (errno == ERANGE || lg < 0 || lg > INT_MAX || *endptr != '\0')
		{
			std::cerr << RED << "Error" << std::endl << "incorrect input: " << RESET << "\'" << av[i] << "\'" << std::endl;
			exit(1);
		}
		i++;
	}
}

deque	get_numbers(char **av)
{
	int		i;
	deque	tmp;

	i = 1;
	while(av[i])
	{
		tmp.push_back(std::atoi(av[i]));
		i++;
	}
	return (tmp);
}
