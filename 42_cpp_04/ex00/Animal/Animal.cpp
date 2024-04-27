/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:08:05 by htouil            #+#    #+#             */
/*   Updated: 2023/12/15 17:31:29 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("chi animal")
{
	std::cout << INDIGO << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << INDIGO << "Animal constructor called" << RESET << std::endl;
	this->type = type;
}


Animal::Animal(const Animal &src)
{
	std::cout << INDIGO << "Animal default copy constructor called" << RESET << std::endl;
	*this = src;
}

Animal	&Animal::operator=(const Animal &src)
{
	std::cout << INDIGO << "Animal copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << INDIGO << "Animal default destructor called" << RESET << std::endl;
}

void	Animal::makeSound()
{
	std::cout << "chi sound" << std::endl;
}

std::string	Animal::getType()
{
	return (this->type);
}
