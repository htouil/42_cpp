/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:52:22 by htouil            #+#    #+#             */
/*   Updated: 2023/12/15 17:36:05 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << CYAN << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << CYAN << "Dog copy constructor called" << RESET << std::endl;
	*this = src;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << CYAN << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << CYAN << "Dog default destructor called" << RESET << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "WOOF WOOF N-" << std::endl;
}
