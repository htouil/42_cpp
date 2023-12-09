/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:33:23 by htouil            #+#    #+#             */
/*   Updated: 2023/12/05 20:19:05 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	if (this != &src)
		*this = src;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->fixed_point = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << GREEN << "Default destructor called" << RESET << std::endl;
	return ;
}

int	Fixed::getRawBits() const
{
	std::cout << BLUE << "getRawBits member function called" << RESET << std::endl;
	return (this->fixed_point);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << BLUE << "setRawBits member function called" << RESET << std::endl;
	this->fixed_point = raw;
}
