/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:08:07 by htouil            #+#    #+#             */
/*   Updated: 2023/12/14 17:38:45 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog/Dog.hpp"
#include "WrongCat/WrongCat.hpp"

int	main()
{
	{
		Animal *meta = new Animal();
		Animal *i = new Cat();
		Animal *j = new Dog();
		Animal	*k;

		k = meta;
		std::cout << i->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << meta->getType() << std::endl;
		std::cout << k->getType() << std::endl;

		std::cout << "--------------------------------------------------------------------------" << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();
		k->makeSound();
		
		delete j;
		delete i;
		delete k;
		// delete meta;
	}
	{
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
	}
	{
		WrongAnimal	*meta = new WrongAnimal();
		WrongAnimal	*i = new WrongCat();
		WrongAnimal *j;

		j = meta;
		std::cout << i->getType() << std::endl;
		std::cout << meta->getType() << std::endl;
		std::cout << j->getType() << std::endl;

		std::cout << "--------------------------------------------------------------------------" << std::endl;
		
		i->makeSound();
		meta->makeSound();
		j->makeSound();

		delete i;
		delete j;
		// delete meta;
	}
	return (0);
}
