/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:59:47 by htouil            #+#    #+#             */
/*   Updated: 2024/08/06 19:29:11 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	clean_stacks(stack &stk1, stack &stk2)
{
	while (!stk1.empty())
	{
		delete[] stk1.top();
		stk1.pop();
	}
	while (!stk2.empty())
	{
		delete[] stk2.top();
		stk2.pop();
	}
}

stack	get_experssion(char *exp)
{
	int		i;
	char	*c;
	stack	tmp;

	for (i = strlen(exp) - 1; i >= 0; i--)
	{
		if (!isspace(exp[i]))
		{
			c = new char[2];
			c[0] = exp[i];
			c[1] = '\0';
			tmp.push(c);
		}
	}
	return (tmp);
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
		if (!isdigit(exp[i]) && !isoperator(exp[i]) && exp[i] != ' ')
			return (1);
		if (isdigit(exp[i]))
			a++;
		if (isoperator(exp[i]))
			b++;
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
	return (0);
}

double	calculate_res(double n1, double n2, char **op, stack &stk1, stack &stk2)
{
	double res;

	res = 0;
	if (*op[0] == '+')
		res = n1 + n2;
	else if (*op[0] == '-')
		res = n1 - n2;
	else if (*op[0] == '*')
		res = n1 * n2;
	else if (*op[0] == '/')
	{
		if (n2 == 0)
		{
			std::cerr << RED << "Error" << std::endl << "dision by 0 is impossible" << RESET << std::endl;
			clean_stacks(stk1, stk2);
			delete[] *op;
			exit(1);
		}
		res = n1 / n2;
	}
	return (res);
}

int		count_fractional_digits(char *value)
{
	int			n;
	int			i;

	n = 0;
	i = 0;
	while (value[i] != '.')
		i++;
	if (value[i] == '.')
	{
		while (value[i] && value[++i] != '0')
			n++;
		if (n > 2)
			return (2);
	}
	return (n);
}

void	calculate_expression(stack &stk1)
{
	stack	stk2;
	char	buffer[50];
	char	*tmp;
	char	*op;
	double	n1, n2;
	double	res;
	int		n;

	while (!stk1.empty())
	{
		if (isdigit(stk1.top()[0]))
		{
			stk2.push(stk1.top());
			stk1.pop();
		}
		if (isoperator(stk1.top()[0]))
		{
			res = 0;
			n2 = atof(stk2.top());
			delete[] stk2.top();
			stk2.pop();
			n1 = atof(stk2.top());
			delete[] stk2.top();
			stk2.pop();
			op = new char[2];
			std::strcpy(op, stk1.top());
			delete[] stk1.top();
			stk1.pop();
			res = calculate_res(n1, n2, &op, stk1, stk2);
			delete[] op;
			sprintf(buffer, "%f", res);
			tmp = new char[strlen(buffer) + 1];
			std::strcpy(tmp, buffer);
			stk2.push(tmp);
		}
	}
	if (!stk2.empty())
	{
		n = count_fractional_digits(stk2.top());
		std::cout << std::fixed << std::setprecision(n) << atof(stk2.top()) << std::endl;
		delete[] stk2.top();
		stk2.pop();
	}
}

void	parse_calculate_expression(char *exp)
{
	stack	stk;

	if (parse_expression(exp) == 1)
	{
		std::cerr << RED << "Error" << std::endl << "bad expression" << RESET << std::endl;;
		exit(1);
	}
	stk = get_experssion(exp);
	calculate_expression(stk);
}
