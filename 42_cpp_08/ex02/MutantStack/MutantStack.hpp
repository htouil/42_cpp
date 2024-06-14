/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:26:29 by htouil            #+#    #+#             */
/*   Updated: 2024/06/14 17:12:05 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>

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
class MutantStack : public std::stack<T>
{
	public:
					MutantStack();
					MutantStack(const MutantStack &src);
		MutantStack	&operator=(const MutantStack &src);
					~MutantStack();

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin();
		iterator	end();
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		const_iterator	cbegin();
		const_iterator	cend();
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
		reverse_iterator	rbegin();
		reverse_iterator	rend();
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		const_reverse_iterator	crbegin();
		const_reverse_iterator	crend();
};

#endif