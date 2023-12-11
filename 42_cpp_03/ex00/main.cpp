/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:49:18 by htouil            #+#    #+#             */
/*   Updated: 2023/12/09 17:40:52 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("hatim");
	ClapTrap	b("amira");
	ClapTrap	c("anas");

	a.setAttackDamage(5);
	b.setAttackDamage(3);
	c.setAttackDamage(0);
	a.displayStats();
	b.displayStats();
	c.displayStats();

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	a.attack(b.itsName());
	if (a.itsHealth() > 0 && a.itsEnergy() > 0)
		b.takeDamage(a.itsDamage());

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	c.attack(a.itsName());
	if (c.itsHealth() > 0 && c.itsEnergy() > 0)
		a.takeDamage(c.itsDamage());

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	a.attack(c.itsName());
	if (a.itsHealth() > 0 && a.itsEnergy() > 0)
		c.takeDamage(a.itsDamage());

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	b.displayStats();
	b.beRepaired(2);

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	c.setAttackDamage(6);

	c.attack(b.itsName());
	if (c.itsHealth() > 0 && c.itsEnergy() > 0)
		b.takeDamage(c.itsDamage());

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	b.displayStats();
	b.beRepaired(10);
	b.displayStats();
	return (0);
}
