/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:42:03 by htouil            #+#    #+#             */
/*   Updated: 2023/12/15 17:56:09 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << YELLOW << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << YELLOW << "WrongCat default copy constructor called" << RESET << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	std::cout << YELLOW << "WrongCat copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "WrongCat default destructor called" << RESET << std::endl;
}

void	WrongCat::makeSound()
{
	std::cout << "BALAK BALAK" << std::endl;
}
