/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:25:09 by htouil            #+#    #+#             */
/*   Updated: 2024/06/14 19:31:29 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack/MutantStack.hpp"
#include "MutantStack/MutantStack.tpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;

		MutantStack<int>									mstack1;
		MutantStack<int>::iterator							it;

		mstack1.push(5);
		mstack1.push(5);
		mstack1.push(5);
		mstack1.push(5);
		mstack1.push(5);
		std::cout << GOLD << "mstack1: " << RESET << std::endl;
		for (it = mstack1.begin(); it != mstack1.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		it = mstack1.begin();
		*it = 1;
		std::cout << "first element of mstack1: " << *it << std::endl;
		*it = 5;

		MutantStack<int>					mstack2(mstack1);
		MutantStack<int>::const_iterator	cit;

		std::cout << GOLD << "mstack2: " << RESET << std::endl;
		for (cit = mstack2.cbegin(); cit != mstack2.cend(); cit++)
			std::cout << *cit << " ";
		std::cout << std::endl;
		cit = mstack2.cbegin();
		std::cout << "last element of mstack2: " << *cit << std::endl;

		MutantStack<int>					mstack3;
		MutantStack<int>::reverse_iterator	rit;

		mstack3 = mstack1;
		std::cout << GOLD << "mstack3: " << RESET << std::endl;
		for (rit = mstack3.rend(); rit != mstack3.rbegin(); rit--)
			std::cout << *rit << " ";
		std::cout << std::endl;
		rit = mstack3.rend();
		*rit = 1;
		std::cout << "first element of mstack3: " << *rit << std::endl;
		*rit = 5;

		MutantStack<int>							mstack4(mstack1);
		MutantStack<int>::const_reverse_iterator	crit;

		std::cout << GOLD << "mstack4: " << RESET << std::endl;
		for (crit = mstack4.crend(); crit != mstack4.crbegin(); crit--)
			std::cout << *crit << " ";
		std::cout << std::endl;
		crit = mstack4.crend();
		std::cout << "last element of mstack4: " << *crit << std::endl;
	}

	// {
	// 	std::cout << std::endl;
	// 	std::cout << "--------------------------------------------------------------------------" << std::endl;
	// 	std::cout << std::endl;
	// }

	// {
	// 	std::cout << YELLOW << "------TEST 2------" << RESET << std::endl;

	// }
	return (0);
}