/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:05:38 by htouil            #+#    #+#             */
/*   Updated: 2023/12/08 17:05:55 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					fixed_point;
		static const int	fract_bits = 8;
	public:
							Fixed();
							Fixed(const Fixed &src);
		Fixed				&operator=(const Fixed &src);
							~Fixed();
							Fixed(const int num);
							Fixed(const float num);

		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		int					toInt() const;
		float				toFloat() const;

		//comparison operation functions:
		bool				operator>(const Fixed &src) const;
		bool				operator<(const Fixed &src) const;
		bool				operator>=(const Fixed &src) const;
		bool				operator<=(const Fixed &src) const;
		bool				operator==(const Fixed &src) const;
		bool				operator!=(const Fixed &src) const;

		//arithmetic operation functions:	
		Fixed				operator+(const Fixed &src) const;
		Fixed				operator-(const Fixed &src) const;
		Fixed				operator*(const Fixed &src) const;
		Fixed				operator/(const Fixed &src) const;

		//increment/decrement operation functions:
		Fixed				&operator++();
		Fixed				operator++(int);
		Fixed				&operator--();
		Fixed				operator--(int);

		//min/max operator functions:
		static Fixed		&min(Fixed &src1, Fixed &src2);
		static const Fixed	&min(const Fixed &src1, const Fixed &src2);
		static Fixed		&max(Fixed &src1, Fixed &src2);
		static const Fixed	&max(const Fixed &src1, const Fixed &src2);
};

std::ostream				&operator<<(std::ostream &out, const Fixed &src);

#endif
