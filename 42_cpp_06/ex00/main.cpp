/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:02:00 by htouil            #+#    #+#             */
/*   Updated: 2024/05/17 02:25:43 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter/ScalarConverter.hpp"


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Wrong number of parameters" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
