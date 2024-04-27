/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:40:50 by htouil            #+#    #+#             */
/*   Updated: 2023/12/15 17:55:26 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("N/A")
{
	std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << GREEN << "WrongAnimal default copy constructor called" << RESET << std::endl;
	*this = src;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << GREEN << "WrongAnimal copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal default destructor called" << RESET << std::endl;
}

void	WrongAnimal::makeSound()
{
	std::cout << "NTG" << std::endl;
}

std::string	WrongAnimal::getType()
{
	return (this->type);
}
