/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:44:31 by htouil            #+#    #+#             */
/*   Updated: 2023/12/17 00:44:32 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << CYAN << "Dog constructor called" << RESET << std::endl;
	this->d_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << CYAN << "Dog copy constructor called" << RESET << std::endl;
	this->d_brain = new Brain();
	*this->d_brain = *src.d_brain;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << CYAN << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		if (this->d_brain)
			delete d_brain;
		this->type = src.type;
		this->d_brain = new Brain();
		*this->d_brain = *src.d_brain;
	}
	return (*this);
}

Dog::~Dog()
{
	if (this->d_brain)
		delete d_brain;
	std::cout << CYAN << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "WOOF WOOF N-" << std::endl;
}

Brain	&Dog::accessBrain()
{
	return (*this->d_brain);
}
