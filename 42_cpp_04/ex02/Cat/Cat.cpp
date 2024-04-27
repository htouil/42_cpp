/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:43:56 by htouil            #+#    #+#             */
/*   Updated: 2023/12/17 00:43:58 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << TEAL << "Cat constructor called" << RESET << std::endl;
	this->c_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << TEAL << "Cat copy constructor called" << RESET << std::endl;
	this->c_brain = new Brain();
	*this->c_brain = *src.c_brain;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << TEAL << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		if (this->c_brain)
			delete this->c_brain;
		this->type = src.type;
		this->c_brain = new Brain();
		*this->c_brain = *src.c_brain;
	}
	return (*this);
}

Cat::~Cat()
{
	if (this->c_brain)
		delete this->c_brain;
	std::cout << TEAL << "Cat destructor called" << RESET << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "MEOW MEOW B-" << std::endl;
}

Brain	&Cat::accessBrain()
{
	return (*this->c_brain);
}
