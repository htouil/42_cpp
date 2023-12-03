/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:28:39 by htouil            #+#    #+#             */
/*   Updated: 2023/12/02 16:35:38 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*z1;
	Zombie	*z2;

	z1 = newZombie("hatim");
	z1->announce();
	delete z1;
	std::cout << "------------------------------------" << std::endl;
	z2 = newZombie("anas");
	z2->announce();
	delete z2;
	std::cout << "------------------------------------" << std::endl;
	randomChump("amira");
	return (0);
}