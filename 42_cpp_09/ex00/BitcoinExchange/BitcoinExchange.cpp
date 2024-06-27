/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:57:40 by htouil            #+#    #+#             */
/*   Updated: 2024/06/27 23:56:51 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange/BitcoinExchange.hpp"

void	delete_arr(char **arr)
{
	if (arr[0])
		delete[] arr[0];
	if (arr[1])
		delete[] arr[1];
	delete[] arr;
}

char	**split(std::string line, char delim)
{
	size_t	pos;
	size_t	rest;
	char	**res;

	res = new char *[2];
	res[0] = NULL;
	res[1] = NULL;
	pos = line.find(delim);
	if (pos != std::string::npos)
	{
		res[0] = new char [pos + 1];
		std::strncpy(res[0], line.c_str(), pos);
		res[0][pos] = '\0';
		rest = line.length() - pos - 1;
		res[1] = new char [rest + 1];
		std::strncpy(res[1], line.c_str() + pos + 1, rest);
		res[1][rest] = '\0';
	}
	else
	{
		res[0] = new char [line.length() + 1];
		std::strcpy(res[0], line.c_str());
	}
	return (res);
}

map	getDataBase()
{
	map			tmpbase;
	std::string	line;
	char		**set;
	double		x;
	std::ifstream	datafile("data.csv");

	if (!datafile.is_open())
	{
		std::cerr << RED <<  "Error\n" << std::endl << "Can't open the database file!" << RESET << std::endl;
		exit(1);
	}
	std::getline(datafile, line);
	while (std::getline(datafile, line))
	{
		set = split(line, ',');
		// std::cout << "\'" << set[0] << "\'" << " | " << "\'" << set[1] << "\'" << std::endl;
		x = atof(set[1]);
		tmpbase.insert(std::make_pair(std::string(set[0]), x));
		delete_arr(set);
	}
	return (tmpbase);
}

void	parse_display_input(std::ifstream inputfile)
{
	
}
