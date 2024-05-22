/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:14:58 by htouil            #+#    #+#             */
/*   Updated: 2024/05/22 17:44:20 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
}

int	one_third_chance()
{
	int	i;

	std::srand(time(NULL));
	i = rand() % 3;
	return (i);
}

Base	*generate()
{
	int		i;

	i = one_third_chance();
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else if (i == 2)
		return (new C());
	return (NULL);
}

void	identify(Base *p)
{
	std::cout << "The type of the object pointed to by " << GREEN << "'*p'" << RESET << " is: ";
	if (dynamic_cast<A*>(p))
		std::cout << YELLOW << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << YELLOW << "C" << RESET << std::endl;
}

void	identify(Base &p)
{
	std::cout << "The type of the object pointed to by " << GREEN << "'&p'" << RESET << " is: ";
	try
	{
		A	&a = dynamic_cast<A&>(p);

		(void)a;
		std::cout << YELLOW << "A" << RESET << std::endl;
	}
	catch (const std::bad_cast &e)
	{
		try
		{
			B	&b = dynamic_cast<B&>(p);

			(void)b;
			std::cout << YELLOW << "B" << RESET << std::endl;
		}
		catch (const std::bad_cast &e)
		{
			try
			{
				C	&c = dynamic_cast<C&>(p);

				(void)c;
				std::cout << YELLOW << "C" << RESET << std::endl;
			}
			catch (const std::bad_cast &e)
			{
				std::cerr << RED << "Bad cast exception: " << RESET << e.what() << std::endl;
			}
		}
	}
}
