/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:48:56 by htouil            #+#    #+#             */
/*   Updated: 2024/06/15 20:02:45 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind/easyfind.hpp"
#include "easyfind/easyfind.tpp"
#include <vector>
#include <list>

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;

		std::vector<int> vec;

		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		::easyfind(vec, 5);
	}

	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << YELLOW << "------TEST 2-----" << RESET << std::endl;

		std::list<int> lst;

		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);
		::easyfind(lst, 0);
	}
	return (0);
}
