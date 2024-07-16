/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:57:44 by htouil            #+#    #+#             */
/*   Updated: 2024/07/16 20:35:04 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		vector			database;
		vector			input;
		std::ifstream	inputfile(av[1]);

		database = getDataBase();
		if (!inputfile.is_open())
		{
			std::cerr << RED <<  "Error\n" << std::endl << "Can't open the input file!" << RESET << std::endl;
			return (1);
		}
		parse_display_input(inputfile, database);
	}
	else
	{
		std::cerr << RED <<  "Error\n" << std::endl << "Wrong number of arguments!" << RESET << std::endl;
		return (1);
	}
	return (0);
}
