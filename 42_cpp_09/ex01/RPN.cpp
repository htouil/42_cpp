/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:59:47 by htouil            #+#    #+#             */
/*   Updated: 2024/07/19 20:54:07 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

stack	get_experssion(char *exp)
{
	int		i;
	char	c[2];
	stack	tmp;

	for (i = strlen(exp) - 1; i >= 0; i--)
	{
		if (exp[i] != ' ')
		{
			c[0] = exp[i];
			c[1] = '\0';
			tmp.push(c);
		}
	}
	return (tmp);
}

void	print_stack(stack stk)
{
	stack	tmp;

	while(!stk.empty())
	{
		std::cout << stk.top()[0] << ' ';
		tmp.push(stk.top());
		stk.pop();
	}
	std::cout << std::endl;
}

bool	isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int	parse_expression(char *exp)
{
	unsigned int	i;
	int				a,b;

	if (exp[0] == ' ' || !isdigit(exp[0]) || exp[strlen(exp) - 1] == ' ' || !isoperator(exp[strlen(exp) - 1]))
		return (1);
	a = 0;
	b = 0;
	for (i = 0; exp[i] != '\0'; i++)
	{
		if (isdigit(exp[i]))
			a++;
		if (isoperator(exp[i]))
			b++;
		if (!isdigit(exp[i]) && !isoperator(exp[i]) && exp[i] != ' ')
			return (1);
	}
	for (i = 0; i < strlen(exp) - 1; i++)
	{
		if (exp[i] == ' ' && (exp[i - 1] == ' ' || exp[i + 1] == ' '))
			return (1);
		if (i != 0)
		{
			if ((isdigit(exp[i]) || isoperator(exp[i])) && (exp[i - 1] != ' ' || exp[i + 1] != ' '))
				return (1);
		}
	}
	if (a != b + 1)
		return (1);
	// vector::iterator	it;

	// if (*(vec.begin()) == ' ' || !isdigit(*(vec.begin())) || *(--vec.end()) == ' ' || !isoperator(*(--vec.end())))
	// 	return (1);
	// for (it = vec.begin(); it != vec.end(); it++)
	// {
	// 	if (!isoperator(*it) && !isdigit(*it) && *it != ' ')
	// 		return (1);
	// }
	// for (it = vec.begin(); it != (--vec.end()); it++)
	// {
	// 	if (*it == ' ' && (*(it - 1) == ' ' || *(it + 1) == ' '))
	// 		return (1);
	// 	if (it != vec.begin())
	// 	{
	// 		if ((isdigit(*it) || isoperator(*it)) && (*(it - 1) != ' ' || *(it + 1) != ' '))
	// 			return (1);
	// 	}
	// }
	// if (std::count_if(vec.begin(), vec.end(), isdigit) != std::count_if(vec.begin(), vec.end(), isoperator) + 1)
	// 	return (1);
	// std::cout << "size : " << vec.size() << std::endl;
	// std::cout << "begin : " << *(vec.begin()) << " end : " << *(--vec.end()) << std::endl;
	return (0);
}

void	calculate_expression(stack &stk1)
{
	stack	stk2;
	char	op, n1, n2;
	double	res;

	while (stk1.size() == 1)
	{
		if (isdigit(stk1.top()[0]))
		{
			stk2.push(stk1.top());
			stk1.pop();
		}
		else if (isoperator(stk1.top()[0]))
		{
			
		}
	}
}

void	parse_calculate_expression(char *exp)
{
	stack	stk;

	if (parse_expression(exp) == 1)
	{
		std::cerr << RED << "bad expression" << RESET << std::endl;;
		exit(1);
	}
	stk = get_experssion(exp);
	print_stack(stk);
	// calculate_expression(stk);
	//might wanna switch to std::stack<char *>
}
