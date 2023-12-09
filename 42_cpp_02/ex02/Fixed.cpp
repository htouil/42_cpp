/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:06:09 by htouil            #+#    #+#             */
/*   Updated: 2023/12/08 17:02:20 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	if (this != &src)
		*this = src;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->fixed_point = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	return ;
}

int	Fixed::getRawBits() const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(const int raw)
{
	this->fixed_point = raw;
}

Fixed::Fixed(const int num)
{
	this->fixed_point = num << this->fract_bits;
	return ;
}

Fixed::Fixed(const float num)
{
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

//comparison operation functions:
bool	Fixed::operator>(const Fixed &src) const
{
	return (this->fixed_point > src.getRawBits());
}

bool	Fixed::operator<(const Fixed &src) const
{
	return (this->fixed_point < src.getRawBits());
}

bool	Fixed::operator>=(const Fixed &src) const
{
	return (this->fixed_point >= src.getRawBits());
}

bool	Fixed::operator<=(const Fixed &src) const
{
	return (this->fixed_point <= src.getRawBits());
}

bool	Fixed::operator==(const Fixed &src) const
{
	return (this->fixed_point == src.getRawBits());
}

bool	Fixed::operator!=(const Fixed &src) const
{
	return (this->fixed_point != src.getRawBits());
}

//arithmetic operation functions:
Fixed	Fixed::operator+(const Fixed &src) const
{
	return ((Fixed)(this->toFloat() + src.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	return ((Fixed)(this->toFloat() - src.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	return ((Fixed)(this->toFloat() * src.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	return ((Fixed)(this->toFloat() / src.toFloat()));
}

//increment/decrement operation functions:
Fixed	&Fixed::operator++()
{
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	
	*this = operator++();
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->fixed_point--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	*this = operator--();
	return (tmp);
}

//min/max operator functions:
Fixed	&Fixed::min(Fixed &src1, Fixed &src2)
{
	if (src1 < src2)
		return (src1);
	return (src2);
}

const Fixed	&Fixed::min(const Fixed &src1, const Fixed &src2)
{
	if (src1 < src2)
		return (src1);
	return (src2);
}

Fixed	&Fixed::max(Fixed &src1, Fixed &src2)
{
	if (src1 > src2)
		return (src1);
	return (src2);
}

const Fixed	&Fixed::max(const Fixed &src1, const Fixed &src2)
{
	if (src1 > src2)
		return (src1);
	return (src2);
}
