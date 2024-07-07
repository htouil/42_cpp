/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:57:40 by htouil            #+#    #+#             */
/*   Updated: 2024/07/07 17:47:09 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	delete_arr(char **arr)
{
	if (arr[0])
		delete[] arr[0];
	if (arr[1])
		delete[] arr[1];
	delete[] arr;
}

char	**split_elements(std::string line, char delim)
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
		set = split_elements(line, ',');
		// std::cout << "\'" << set[0] << "\'" << " | " << "\'" << set[1] << "\'" << std::endl;
		x = atof(set[1]);
		tmpbase.insert(std::make_pair(std::string(set[0]), x));
		delete_arr(set);
	}
	return (tmpbase);
}

int	count_elements(std::string line, char c)
{
	int	i;
	int	x;

	x = 0;
	for (i = 0; i < line.length(); i++)
	{
		if (line[i] == c)
			x++;
	}
	return (x);
}

int	parse_elements(char **set)
{
	if (!set[0] || !set[1])
		return (1);
	
}

void	parse_display_input(std::ifstream inputfile)
{
	std::string	line;
	char		**set;

	std::getline(inputfile, line);
	if (!line.empty())
	{
		std::cerr << RED << "The input file is empty!" << RESET << std::endl;
		exit(1);
	}
	if (line != "date | value")
	{
		std::cerr << RED << "Wrong file content!" << RESET << std::endl;
		exit(1);
	}
	while (std::getline(inputfile, line))
	{
		if (count_elements(line, '|') != 1)
			continue ;
		set = split_elements(line, '|');
		parse_elements(set);
		delete_arr(set);
	}
}
