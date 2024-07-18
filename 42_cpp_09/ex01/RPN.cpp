/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:59:47 by htouil            #+#    #+#             */
/*   Updated: 2024/07/18 02:50:21 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

vector	get_experssion(char *exp)
{
	int		i;
	vector	tmp;

	i = 0;
	while (exp[i])
	{
		tmp.push_back(exp[i]);
		i++;
	}
	return (tmp);
}

bool	isoperation(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int	parse_expression(vector vec)
{
	vector::iterator	it;

	if (*(vec.begin()) == ' ' || *(--vec.end()) == ' ')
		return (1);
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if (!isoperation(*it) && !isdigit(*it) && *it != ' ')
			return (1);
	}
	for (it = vec.begin(); it != (--vec.end()); it++)
	{
		if (*it == ' ' && (*(it - 1) == ' ' || *(it + 1) == ' '))
			return (1);
		if (it != vec.begin() && it != (--vec.end()))
		{
			if ((isdigit(*it) || isoperation(*it)) && (*(it - 1) != ' ' || *(it + 1) != ' '))
				return (1);
		}
	}
	// std::cout << "size : " << vec.size() << std::endl;
	// int	i, j;
	// i = std::count(vec.begin(), vec.end(), ' ');
	// j = (vec.size() - 1) / 2;
	// if (i != j)
	// 	return (1);
	// std::cout << "begin : " << *(vec.begin()) << " end : " << *(--vec.end()) << std::endl;
	return (0);
}

void	parse_calculate_expression(vector vec)
{
	if (parse_expression(vec) == 1)
	{
		std::cerr << RED << "bad expression" << RESET << std::endl;;
		exit(1);
	}
}
