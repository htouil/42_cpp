/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:22:14 by htouil            #+#    #+#             */
/*   Updated: 2023/12/08 21:27:54 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define GREY    "\033[90m"
# define WHITE   "\033[37m"

class Fixed
{
	private:
		int					fixed_point;
		static const int	fract_bits = 8;
	public:
				Fixed();
				Fixed(const Fixed &src);
		Fixed	&operator=(const Fixed &src);
				~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
