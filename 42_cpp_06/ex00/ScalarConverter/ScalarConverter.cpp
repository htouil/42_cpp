/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:06:27 by htouil            #+#    #+#             */
/*   Updated: 2024/05/17 02:26:37 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// void	convert_to_int(std::string to_be_converted, int length)
// {
// 	if ()
// }

// void	convert_to_char(std::string to_be_converted, int length)
// {
// 	if (length == 1)
	
// }

// void	convert_to_float(std::string to_be_converted, int length)
// {
	
// }

// void	convert_to_double(std::string to_be_converted, int length)
// {
	
// }

int	is_int(std::string str)
{
	int	i;
	// int	x;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(isdigit(str[i])))
			return (0);
		i++;
	}
	// x = std::atoi(str.c_str());
	return (1);
}

int	is_double(std::string str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] != '.')
	{
		if (!(isdigit(str[i])))
			return (0);
		i++;
	}
	if (str[i] == '.' && isdigit(str[i + 1]) && str[i + 2] == '\0')
		return (1);
	return (0);
}

int	is_float(std::string str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] != '.')
	{
		if (!(isdigit(str[i])))
			return (0);
		i++;
	}
	if (str[i] == '.' && isdigit(str[i + 1]) && str[i + 2] == 'f' && str[i + 3] == '\0')
		return (1);
	return (0);
}

void	ScalarConverter::convert(std::string to_be_converted)
{
	long	x;
	float	a;
	double	b;

	std::cout << "Converting: " << CYAN << "\"" << to_be_converted << "\"" << RESET << std::endl << std::endl;
	if (to_be_converted.length() > 0)
	{
		if (to_be_converted == "-inff" || to_be_converted == "+inff" || to_be_converted == "nanf"
			|| to_be_converted == "-inf" || to_be_converted == "+inf" || to_be_converted == "nan")
		{
			std::cout << GREEN << "char: " << RESET << "impossible" << std::endl;
			std::cout << GREEN << "int: " << RESET << "impossible" << std::endl;
			if (to_be_converted == "-inf" || to_be_converted == "+inf" || to_be_converted == "nan")
			{
				std::cout << GREEN << "float: " << RESET << to_be_converted + "f" << std::endl;
				std::cout << GREEN << "double: " << RESET << to_be_converted << std::endl;
			}
			else if (to_be_converted == "-inff" || to_be_converted == "+inff")
			{
				std::cout << GREEN << "float: " << RESET << to_be_converted << std::endl;
				std::cout << GREEN << "double: " << RESET << to_be_converted.substr(0, 4) << std::endl;
			}
			else
			{
				std::cout << GREEN << "float: " << RESET << to_be_converted << std::endl;
				std::cout << GREEN << "double: " << RESET << to_be_converted.substr(0, 3) << std::endl;
			}
		}
		else if (is_int(to_be_converted) == 1)
		{
			x = std::atol(to_be_converted.c_str());
			if (x > 2147483647 || x < -2147483648)
			{
				std::cout << GREEN << "char: " << RESET << "impossible" << std::endl;
				std::cout << GREEN << "int: " << RESET << "impossible" << std::endl;
			}
			else
			{
				if (x > 126 || x < 0)
					std::cout << GREEN << "char: " << RESET << "impossible" << std::endl;
				else
					std::cout << GREEN << "char: " << RESET << "\'" <<static_cast<char>(x) << "\'" << std::endl;
				std::cout << GREEN << "int: " << RESET << x << std::endl;
			}
			std::stringstream(to_be_converted) >> a;
			std::cout << GREEN << "float: " << RESET << a << ".0f" << std::endl;
			std::stringstream(to_be_converted) >> b;
			std::cout << GREEN << "double: " << RESET << b << ".0" << std::endl;
		}
		return ;
	}
	std::cout << GREEN << "char: " << RESET << "empty" << std::endl;
	std::cout << GREEN << "int: " << RESET << "empty" << std::endl;
	std::cout << GREEN << "float: " << RESET << "empty" << std::endl;
	std::cout << GREEN << "double: " << RESET << "empty" << std::endl;
	return ;
}
