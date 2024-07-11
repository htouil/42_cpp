/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:57:40 by htouil            #+#    #+#             */
/*   Updated: 2024/07/11 21:55:47 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	is_empty_string(std::string line)
{
	std::string::iterator	it;
	for (it = line.begin(); it != line.end(); it++)
	{
		if (!std::isspace(*it))
			return (0);
	}
	return (1);
}

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
		x = atof(set[1]);
		tmpbase.insert(std::make_pair(std::string(set[0]), x));
		delete_arr(set);
	}
	return (tmpbase);
}

// int	count_elements(std::string line, char c)
// {
// 	int	i;
// 	int	x;

// 	x = 0;
// 	for (i = 0; i < line.length(); i++)
// 	{
// 		if (line[i] == c)
// 			x++;
// 	}
// 	return (x);
// }

bool	is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return (true);
	return (false);
}

int	parse_date(char **set)
{
	int			day, month, year;
	std::string	date(set[0]);

	if (std::count(date.begin(), date.end(), '-') != 2 || sscanf(set[0], "%d-%d-%d", &year, &month, &day) != 3)
		return (1);
	else
	{
		if ((year < 0 || year > 2017) || (month < 1 || month > 12))
			return (1);
		if (month <= 7 && month != 2)
		{
			if ((month % 2 == 0) && (day < 1 || day > 30))
				return (1);
			else if ((month % 2 != 0) && (day < 1 || day > 31))
				return (1);
		}
		else
		{
			if ((month % 2 == 0) && (day < 1 || day > 31))
				return (1);
			else if ((month % 2 != 0) && (day < 1 || day > 30))
				return (1);
		}
		if (month == 2)
		{
			if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (day < 1 || day > 29))
				return (1);
			else if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (day < 1 || day > 28))
				return (1);
		}
		if (year == 2017 && month == 2 && day > 1)
			return (1);
	}
	return (0);
}

int	parse_elements(char **set, std::string line)
{
	double	x;

	if (!set[0] || !set[1])
	{
		std::cout << "Error: bad input => " << CYAN << line << RESET << std::endl;
		return (1);
	}
	x = std::stod(set[1]);
	if (x > 1000)
	{
		std::cout << "Error: input value is too large => " << CYAN << set[1] << RESET << std::endl;
		return (1);
	}
	else if (x < 0)
	{
		std::cout << "Error: input value is negative => " << CYAN << set[1] << RESET << std::endl;
		return (1);
	}
	if (parse_date(set) == 1)
	{
		std::cout << "Error: wrong date => " << CYAN << set[0] << RESET << std::endl;
		return (1);
	}
	return (0);
}

// void	display_elements(char **set)
// {
	
// }

void	parse_display_input(std::ifstream &inputfile)
{
	std::string	line;
	char		**set;

	std::getline(inputfile, line);
	if (line.empty() || is_empty_string(line) == 1)
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
		// std::cout << YELLOW << line << RESET << std::endl;
		if (is_empty_string(line) == 1)
			continue ;
		if (std::count(line.begin(), line.end(), '|') != 1)
		{
			std::cout << "Error: " << "bad input => " << CYAN << line << RESET << std::endl;
			continue ;
		}
		set = split_elements(line, '|');
		if (parse_elements(set, line) == 1)
			continue ;
		// display_elements(set);
		delete_arr(set);
	}
}
