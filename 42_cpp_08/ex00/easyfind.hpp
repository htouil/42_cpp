/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:49:28 by htouil            #+#    #+#             */
/*   Updated: 2024/06/10 20:55:17 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>

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

typedef std::vector<int>::iterator iterator;

template <typename T>
iterator    easyfind(T vec, int to_find);


#endif