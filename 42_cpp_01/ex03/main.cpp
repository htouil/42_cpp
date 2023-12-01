/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:09:01 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 20:36:10 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA/HumanA.hpp"
#include "HumanB/HumanB.hpp"

int	main()
{
	{
		Weapon	club("Poké Ball");
		HumanA	bob("Bob", club);

		bob.attack();
		club.setType("Knife glove");
		bob.attack();
	}
	{
		std::cout << "------------------------------------------------" << std::endl;
	}
	{
		Weapon	club("Portal gun");
		HumanB	hatim("Hatim");

		hatim.setWeapon(club);
		hatim.attack();
		club.setType("Buster sword");
		hatim.attack();
	}
	return (0);
}