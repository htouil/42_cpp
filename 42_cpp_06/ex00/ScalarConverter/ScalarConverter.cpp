/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:06:27 by htouil            #+#    #+#             */
/*   Updated: 2024/05/17 18:38:44 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	is_int(std::string str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
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

void	handle_special_cases(std::string to_be_converted)
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

void	handle_ints(std::string to_be_converted)
{
	int		i;
	long	x;

	x = std::atol(to_be_converted.c_str());
	if (x > INT_MAX || x < INT_MIN)
	{
		std::cout << GREEN << "char: " << RESET << "impossible" << std::endl;
		std::cout << GREEN << "int: " << RESET << "impossible" << std::endl;
	}
	else
	{
		if (x > 126 || x < 0)
			std::cout << GREEN << "char: " << RESET << "impossible" << std::endl;
		else if ((x >= 0 && x <= 31) || x == 127)
			std::cout << GREEN << "char: " << RESET << "non displayable" << std::endl;
		else
			std::cout << GREEN << "char: " << RESET << "\'" << static_cast<char>(x) << "\'" << std::endl;
		std::cout << GREEN << "int: " << RESET << x << std::endl;
	}
	std::stringstream(to_be_converted) >> i;
	std::cout << GREEN << "float: " << RESET << i << ".0f" << std::endl;
	std::cout << GREEN << "double: " << RESET << i << ".0" << std::endl;
}

void	handle_doubles(std::string to_be_converted)
{
	double	d;
	long	x;

	std::stringstream(to_be_converted) >> d;
	x = static_cast<long>(d);
	if (x > INT_MAX || x < INT_MIN)
	{
		std::cout << GREEN << "char: " << RESET << "impossible" << std::endl;
		std::cout << GREEN << "int: " << RESET << "impossible" << std::endl;
	}
	else
	{
		if (x > 126 || x < 0)
			std::cout << GREEN << "char: " << RESET << "impossible" << std::endl;
		else
			std::cout << GREEN << "char: " << RESET << "\'" << static_cast<char>(x) << "\'" << std::endl;
		std::cout << GREEN << "int: " << RESET << x << std::endl;
	}
	std::cout << GREEN << "float: " << RESET << std::fixed << std::setprecision(1) << d << "f" << std::endl;
	std::cout << GREEN << "double: " << RESET << std::fixed << std::setprecision(1) << d << std::endl;
}

void	handle_floats(std::string to_be_converted)
{
	std::string	tmp;

	tmp = to_be_converted.substr(0, to_be_converted.length() - 1);
	handle_doubles(tmp);
}

void	ScalarConverter::convert(std::string to_be_converted)
{
	std::cout << "Converting: " << CYAN << "\"" << to_be_converted << "\"" << RESET << std::endl << std::endl;
	if (to_be_converted.length() > 0)
	{
		if (to_be_converted == "-inff" || to_be_converted == "+inff" || to_be_converted == "nanf"
			|| to_be_converted == "-inf" || to_be_converted == "+inf" || to_be_converted == "nan")
			handle_special_cases(to_be_converted);
		else if (is_int(to_be_converted) == 1)
			handle_ints(to_be_converted);
		else if (is_double(to_be_converted) == 1)
			handle_doubles(to_be_converted);
		else if (is_float(to_be_converted) == 1)
			handle_floats(to_be_converted);
		else
		{
			std::cout << GREEN << "char: " << RESET << "impossible" << std::endl;
			std::cout << GREEN << "int: " << RESET << "impossible" << std::endl;
			std::cout << GREEN << "float: " << RESET << "impossible" << std::endl;
			std::cout << GREEN << "double: " << RESET << "impossible" << std::endl;
		}
		return ;
	}
	std::cout << GREEN << "char: " << RESET << "empty" << std::endl;
	std::cout << GREEN << "int: " << RESET << "empty" << std::endl;
	std::cout << GREEN << "float: " << RESET << "empty" << std::endl;
	std::cout << GREEN << "double: " << RESET << "empty" << std::endl;
}
