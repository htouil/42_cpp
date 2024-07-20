/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:59:47 by htouil            #+#    #+#             */
/*   Updated: 2024/07/20 02:38:47 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

stack	get_experssion(char *exp)
{
	int		i;
	char	*c;
	stack	tmp;

	for (i = strlen(exp) - 1; i >= 0; i--)
	{
		if (!isspace(exp[i]))
		{
			c = &exp[i];
			c[1] = '\0';
			tmp.push(c);
		}
	}
	return (tmp);
}

void	print_stack(stack stk)
{
	while(!stk.empty())
	{
		std::cout << *stk.top() << " ";
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
	return (0);
}

double	calculate_res(double n1, double n2, char *op)
{
	double res;

	if (op[0] == '+')
		res = n1 + n2;
	else if (op[0] == '-')
		res = n1 - n2;
	else if (op[0] == '*')
		res = n1 * n2;
	else if (op[0] == '/')
		res = n1 / n2;
	return (res);
}

void	calculate_expression(stack &stk1)
{
	stack	stk2;
	char	*op;
	double	n1, n2;
	double	res;
	char	*buffer;

	while (stk1.size() != 1)
	{
		std::cout << "stk1 : ";
		print_stack(stk1);
		std::cout << "stk2 : ";
		print_stack(stk2);
		if (isdigit(stk1.top()[0]))
		{
			stk2.push(stk1.top());
			stk1.pop();
		}
		else if (isoperator(stk1.top()[0]))
		{
			//smtg wrong here
			n2 = atof(stk2.top());
			stk2.pop();
			n1 = atof(stk2.top());
			stk2.pop();
			op = stk1.top();
			stk1.pop();
			res = calculate_res(n1, n2, op);
			sprintf(buffer, "%.2f", res);
			stk2.push(buffer);
			// std::cout << "n1 : " << n1 << " | n2 : " << n2 << std::endl;
			// std::cout << n1 << " " << op << " " << n2 << " = " << res << std::endl;
			// std::cout << "buffer : " << buffer << std::endl;
			// std::cout << "top after calcul : " << stk2.top() << std::endl << std::endl << std::endl;
		}
	}
	std::cout << std::endl;
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
	// print_stack(stk);
	calculate_expression(stk);
}
