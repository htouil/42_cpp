/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:52:56 by htouil            #+#    #+#             */
/*   Updated: 2023/12/15 17:33:49 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << TEAL << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << TEAL << "Cat copy constructor called" << RESET << std::endl;
	*this = src;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << TEAL << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << TEAL << "Cat default destructor called" << RESET << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "MEOW MEOW B-" << std::endl;
}
