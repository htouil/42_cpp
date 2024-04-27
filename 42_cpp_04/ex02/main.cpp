/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:41:23 by htouil            #+#    #+#             */
/*   Updated: 2024/03/24 22:19:15 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog/Dog.hpp"

int	main()
{
	{
		Animal	*animalArray[10];
		int		i;

		for (i = 0; i < 10; i++)
		{
			animalArray[i] = new Cat();
			std::cout << "*********************" << std::endl;
			animalArray[++i] = new Dog();
			std::cout << "*********************" << std::endl;
		}

		std::cout << "--------------------------------------------------------------------------" << std::endl;

		for (i = 0; i < 10; i++)
		{
			std::cout << "Animal N." << i + 1 << ":" << std::endl;
			std::cout << "  type: " << animalArray[i]->getType() << std::endl;
			std::cout << "  sound: ";
			animalArray[i]->makeSound();
			std::cout << "*********************" << std::endl;
		}
		std::cout << "--------------------------------------------------------------------------" << std::endl;

		for (i = 9; i >= 0; i--)
		{
			delete animalArray[i];
			std::cout << "*********************" << std::endl;
		}
	}
	
	{
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
	}

	{
		Cat	*cat;
		Dog *dog;

		cat = new Cat();
		dog = new Dog();
		
		std::cout << "--------------------------------------------------------------------------" << std::endl;

		cat->accessBrain().setIdea(0, "what's your name?!");
		std::cout << "cat's idea N.0: " << cat->accessBrain().getIdea(0) << std::endl;
		std::cout << "cat's idea N.99: " << cat->accessBrain().getIdea(99) << std::endl;
		std::cout << "**************************************" << std::endl;		
		dog->accessBrain().setIdea(0, "azeikil");
		dog->accessBrain().setIdea(1, "what is your name?!");
		std::cout << "dog's idea N.0: " << dog->accessBrain().getIdea(0) << std::endl;
		std::cout << "dog's idea N.1: " << dog->accessBrain().getIdea(1) << std::endl;
		std::cout << "dog's idea N.99: " << dog->accessBrain().getIdea(99) << std::endl;

		std::cout << "--------------------------------------------------------------------------" << std::endl;

		delete cat;
		delete dog;
	}

	{
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
	}

	// {
	// 	Animal	*animal;

	// 	animal = new Animal();

	// 	std::cout << "--------------------------------------------------------------------------" << std::endl;

	// 	animal->makeSound();

	// 	std::cout << "--------------------------------------------------------------------------" << std::endl;

	// 	delete animal;
	// }
	
	return (0);
}
