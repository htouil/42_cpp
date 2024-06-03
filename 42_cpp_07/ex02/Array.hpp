/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:45:14 by htouil            #+#    #+#             */
/*   Updated: 2024/06/03 20:24:59 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstring>

# define RESET       "\033[0m"
# define RED         "\033[31m"
# define GREEN       "\033[32m"
# define YELLOW      "\033[33m"
# define BLUE        "\033[34m"
# define MAGENTA     "\033[35m"
# define CYAN        "\033[36m"
# define GREY        "\033[90m"
# define WHITE       "\033[37m"
# define GOLD        "\033[38;5;178m"
# define ORANGE      "\033[38;5;202m"
# define PINK        "\033[38;5;206m"
# define PURPLE      "\033[38;5;141m"
# define BROWN       "\033[38;5;94m"
# define BEIGE       "\033[38;5;224m"
# define OLIVE_GREEN "\033[38;5;58m"
# define TEAL        "\033[38;5;30m"
# define AQUA        "\033[38;5;51m"
# define MAROON      "\033[38;5;52m"
# define CRIMSON     "\033[38;5;160m"
# define CORAL       "\033[38;5;203m"
# define SALMON      "\033[38;5;209m"
# define TURQUOISE   "\033[38;5;45m"
# define INDIGO      "\033[38;5;54m"

template<typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	len;
	public:
					Array();
					Array(unsigned int n);
					Array(const Array &src);
		Array		&operator=(const Array &src);
					~Array();

		unsigned int	size();
		T				*getArr();
		T				&operator[](unsigned int i);

		class OutOfBoundsException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class EmptyArrayException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class NegativeSizeInputException : public std::exception
		{
			virtual const char	*what() const throw();
		};

};

#endif