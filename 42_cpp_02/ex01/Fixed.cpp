/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:47:37 by htouil            #+#    #+#             */
/*   Updated: 2023/12/07 16:02:24 by htouil           ###   ########.fr       */
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

Fixed::Fixed(const int num)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	this->fixed_point = num << this->fract_bits;
	return ;
}

Fixed::Fixed(const float num)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	this->fixed_point = roundf(num * (1 << this->fract_bits));
	return ;
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return (out);
}

int	Fixed::toInt() const
{
	return (this->fixed_point >> this->fract_bits);
}

float	Fixed::toFloat() const
{
	return ((float)this->fixed_point / (1 << this->fract_bits));
}
