/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:24:18 by htouil            #+#    #+#             */
/*   Updated: 2024/07/23 16:05:52 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	l()
{
	system("leaks RPN");
}

int	main(int ac, char **av)
{
	atexit(l);
	if (ac == 2)
		parse_calculate_expression(av[1]);
	else
	{
		std::cerr << RED <<  "Error\n" << std::endl << "Wrong number of arguments!" << RESET << std::endl;
		return (1);
	}
	return (0);
}
