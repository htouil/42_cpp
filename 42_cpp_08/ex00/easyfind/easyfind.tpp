/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:50:00 by htouil            #+#    #+#             */
/*   Updated: 2024/06/12 03:37:08 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void	easyfind(T &vec, int to_find)
{
	typename T::const_iterator	it;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		if (*it == to_find)
		{
			std::cout << BLUE << "The searched integer is found in the container." << RESET << std::endl;
			return ;
		}
	}
	std::cerr << RED << "No occurance of the searched integer in the container." << RESET << std::endl;
}


