/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:14:58 by htouil            #+#    #+#             */
/*   Updated: 2024/05/21 18:35:52 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	std::cout << BROWN << "Base destructor called" << RESET << std::endl;
}

A::A()
{
	std::cout << AQUA << "A default constructor called" << RESET << std::endl;
}

B::B()
{
	std::cout << BLUE << "B default constructor called" << RESET << std::endl;
}

C::C()
{
	std::cout << CORAL << "C default constructor called" << RESET << std::endl;
}

std::string	A::getType()
{
	return ("A");
}

std::string	B::getType()
{
	return ("B");
}

std::string	C::getType()
{
	return ("C");
}

int	one_third_chance()
{
	int	i;

	srand(static_cast<unsigned int>(std::time(nullptr)));
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
	std::cout << "The type of the object pointed to by " << GREEN << "'*p'" << RESET << " is: " << YELLOW << p->getType() << RESET << std::endl;
}

void	identify(Base &p)
{
	std::cout << "The type of the object pointed to by " << GREEN << "'&p'" << RESET << " is: " << YELLOW << p.getType() << RESET << std::endl;
}
