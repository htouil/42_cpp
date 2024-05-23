/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:49:42 by htouil            #+#    #+#             */
/*   Updated: 2024/05/20 21:53:39 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer/Serializer.hpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		Data	ptr;
		Data	*tmp;

		ptr.letter = (char)'a';
		std::cout << CYAN << "address of the ptr before serializing: " << RESET << &ptr << std::endl;
		tmp = Serializer::deserialize(Serializer::serialize(&ptr));
		std::cout << CYAN << "address of the ptr after serializing:  " << RESET << tmp << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
	
	{
		std::cout << YELLOW << "------TEST 2------" << RESET << std::endl;
		Data		ptr;
		Data		*tmp;
		uintptr_t	x;

		ptr.letter = (char)'b';
		std::cout << CYAN << "address of the ptr before serializing: " << RESET << &ptr << std::endl;
		x = Serializer::serialize(&ptr);
		std::cout << RED << "integer value of the address: " << RESET << x << std::endl;
		tmp = Serializer::deserialize(x);
		std::cout << CYAN << "address of the ptr after serializing:  " << RESET << tmp << std::endl;
	}
	return (0);
}
