/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:57:44 by htouil            #+#    #+#             */
/*   Updated: 2024/07/14 02:22:28 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		map				database;
		map				input;
		std::ifstream	inputfile(av[1]);

		database = getDataBase();
		// for (map::const_iterator cit = database.begin(); cit != database.end(); cit++)
		// {
		// 	std::cout << "\'" << cit->first << "\'" << " | " << "\'" << cit->second << "\'" << std::endl;
		// }
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
