/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:50:00 by htouil            #+#    #+#             */
/*   Updated: 2024/06/20 19:11:03 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void	easyfind(T &vec, int to_find)
{
	typename T::const_iterator	cit;

	cit = std::find(vec.begin(), vec.end(), to_find);
	if (cit != vec.end())
		std::cout << BLUE << "The searched integer is found in the container." << RESET << std::endl;
	else
		std::cerr << RED << "No occurance of the searched integer in the container." << RESET << std::endl;
}
