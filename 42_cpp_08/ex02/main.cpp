/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:25:09 by htouil            #+#    #+#             */
/*   Updated: 2024/06/15 19:17:08 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack/MutantStack.hpp"
#include "MutantStack/MutantStack.tpp"

int	main()
{
	{
		std::cout << GOLD << "------TEST 1------" << RESET << std::endl;

		MutantStack<int>									mstack1;
		MutantStack<int>::iterator							it;

		mstack1.push(1);
		mstack1.push(2);
		mstack1.push(3);
		mstack1.push(4);
		mstack1.push(5);
		std::cout << "mstack1: " ;
		for (it = mstack1.begin(); it != mstack1.end(); it++)
			std::cout << BLUE << *it << RESET << " ";
		std::cout << std::endl;
		it = mstack1.begin();
		*it = 0;
		std::cout << "first element of mstack1: " << GREEN << *it << std::endl;
		*it = 1;

		std::cout << std::endl << GOLD << "------TEST 2------" << RESET << std::endl;

		MutantStack<int>					mstack2(mstack1);
		MutantStack<int>::const_iterator	cit;

		std::cout << "mstack2: " ;
		for (cit = mstack2.cbegin(); cit != mstack2.cend(); cit++)
			std::cout << BLUE << *cit << RESET << " ";
		std::cout << std::endl;
		cit = mstack2.cbegin();
		std::cout << "first element of mstack2: " << GREEN << *cit << std::endl;

		std::cout << std::endl << GOLD << "------TEST 3------" << RESET << std::endl;
		MutantStack<int>					mstack3;
		MutantStack<int>::reverse_iterator	rit;

		mstack3 = mstack1;
		std::cout << "mstack3: ";
		for (rit = mstack3.rbegin(); rit != mstack3.rend(); ++rit)
			std::cout << BLUE << *rit << RESET << " ";
		std::cout << std::endl;
		rit = mstack3.rbegin();
		*rit = 0;
		std::cout << "last element of mstack3: " << GREEN << *rit << std::endl;
		*rit = 1;

		std::cout << std::endl << GOLD << "------TEST 4------" << RESET << std::endl;
		MutantStack<int>							mstack4(mstack1);
		MutantStack<int>::const_reverse_iterator	crit;

		std::cout << "mstack4: ";
		for (crit = mstack4.crbegin(); crit != mstack4.crend(); ++crit)
			std::cout << BLUE << *crit << RESET << " ";
		std::cout << std::endl;
		crit = mstack4.crbegin();
		std::cout << "last element of mstack4: " << GREEN << *crit << std::endl;
	}
	return (0);
}