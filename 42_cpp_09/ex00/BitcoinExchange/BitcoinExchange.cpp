/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:57:40 by htouil            #+#    #+#             */
/*   Updated: 2024/08/06 19:58:48 by htouil           ###   ########.fr       */
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

char	*trim_str(char **str)
{
	int		len;
	int		i;
	int		j;
	char	*tmp;

	if ((*str) == NULL)
		return (NULL);
	len = std::strlen((*str));
	i = 0;
	while (i < len && std::isspace((*str)[i]))
		i++;
	j = len;
	while (j > i && std::isspace((*str)[j - 1]))
		j--;
	len = j - i;
	tmp = new char [len + 1];
	for (int k = 0; k < len; k++)
		tmp[k] = (*str)[k + i];
	tmp[len] = '\0';
	delete[] (*str);
	return (tmp);
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
	res[0] = new char [pos + 1];
	std::strncpy(res[0], line.c_str(), pos);
	res[0][pos] = '\0';
	rest = line.length() - pos - 1;
	res[1] = new char [rest + 1];
	std::strncpy(res[1], line.c_str() + pos + 1, rest);
	res[1][rest] = '\0';
	res[0] = trim_str(&res[0]);
	res[1] = trim_str(&res[1]);
	return (res);
}

list	getDataBase()
{
	list			tmpbase;
	std::string		line;
	char			**set;
	double			x;
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
		tmpbase.push_back(std::make_pair(std::string(set[0]), x));
		delete_arr(set);
	}
	return (tmpbase);
}

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
		if (year == 2022 && month == 3 && day > 31)
			return (1);
		if (year == 2009 && month == 1 && day < 2)
			return (1);
		if ((year < 2009 || year > 2022) || (month < 1 || month > 12))
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
	}
	return (0);
}

int	parse_elements(char **set, std::string line)
{
	double	x;

	if (std::strlen(set[0]) == 0 || std::strlen(set[1]) == 0)
	{
		std::cout << "Error: bad input => " << line << RESET << std::endl;
		return (1);
	}
	
	x = atof(set[1]);
	if (x > 1000)
	{
		std::cout << "Error: input value is too large => " << set[1] << RESET << std::endl;
		return (1);
	}
	else if (x < 0)
	{
		std::cout << "Error: input value is negative => " << set[1] << RESET << std::endl;
		return (1);
	}
	if (parse_date(set) == 1)
	{
		std::cout << "Error: wrong date => " << set[0] << RESET << std::endl;
		return (1);
	}
	return (0);
}

int		count_fractional_digits(double res)
{
	int			n;
	int			i;
	char		*value;
	char		buffer[20];

	std::sprintf(buffer, "%f", res);
	value = new char[std::strlen(buffer) + 1];
	std::strcpy(value, buffer);
	n = 0;
	i = 0;
	while (value[i] != '.')
		i++;
	while (value[++i] != '0')
		n++;
	delete[] value;
	return (n);
}

bool	pair_compare(const std::pair<std::string, double> &pair, const std::string &date)
{
	return (pair.first < date);
}

void	display_elements(char **set, list database)
{
	list::iterator	it;
	std::string			date(set[0]);
	int					n;
	double				res;

	if (date == "2022-03-30" || date == "2022-03-31")
	{
		it = database.end();
		it--;
	}
	else
	{
		it = std::lower_bound(database.begin(), database.end(), date, pair_compare);
		if (it != database.begin() && it->first != date)
			--it;
	}
	res = it->second * atof(set[1]);
	n = count_fractional_digits(res);
	std::cout << set[0] << " => " << set[1] << " = " << std::fixed << std::setprecision(n) << res << std::endl;
}

void	parse_display_input(std::ifstream &inputfile, list databse)
{
	std::string	line;
	char		**set;
	char		**title;

	std::getline(inputfile, line);
	if (line.empty() || is_empty_string(line) == 1)
	{
		std::cerr << RED << "The input file is empty!" << RESET << std::endl;
		exit(1);
	}
	title = split_elements(line, '|');
	if (strcmp(title[0], "date") || strcmp(title[1], "value"))
	{
		std::cerr << RED << "Wrong file content!" << RESET << std::endl;
		delete_arr(title);
		exit(1);
	}
	delete_arr(title);
	while (std::getline(inputfile, line))
	{
		if (is_empty_string(line) == 1)
			continue ;
		if (std::count(line.begin(), line.end(), '|') != 1)
		{
			std::cout << "Error: " << "bad input => " << line << RESET << std::endl;
			continue ;
		}
		set = split_elements(line, '|');
		if (parse_elements(set, line) == 1)
			continue ;
		display_elements(set, databse);
		delete_arr(set);
	}
}
