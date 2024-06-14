/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:25:09 by htouil            #+#    #+#             */
/*   Updated: 2024/06/14 17:29:50 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack/MutantStack.hpp"
#include "MutantStack/MutantStack.tpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;

		MutantStack<int>	mstack1;
		MutantStack<int>	mstack3;

		mstack1.push(5);
		mstack1.push(5);
		mstack1.push(5);
		mstack1.push(5);
		mstack1.push(5);
		MutantStack<int>	mstack2(mstack1);
		mstack3 = mstack1;
	}

	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}

	// {
	// 	std::cout << YELLOW << "------TEST 2------" << RESET << std::endl;

	// }
	return (0);
}