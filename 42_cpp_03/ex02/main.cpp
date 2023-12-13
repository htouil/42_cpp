/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:55:12 by htouil            #+#    #+#             */
/*   Updated: 2023/12/13 17:21:29 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap/FragTrap.hpp"

int	main()
{
	ClapTrap	a("hatim");
	ScavTrap	b("amira");
	FragTrap	c("anas");
	FragTrap	d;

	a.setAttackDamage(10);
	a.displayStats();
	b.displayStats();
	c.displayStats();
	d.displayStats();

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	a.attack(b.itsName());
	if (a.itsHealth() > 0 && a.itsEnergy() > 0)
		b.takeDamage(a.itsDamage());
	a.displayStats();
	b.displayStats();

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	c.attack(a.itsName());
	if (c.itsHealth() > 0 && c.itsEnergy() > 0)
		a.takeDamage(c.itsDamage());
	a.displayStats();
	c.displayStats();

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	a.attack(c.itsName());
	if (a.itsHealth() > 0 && a.itsEnergy() > 0)
		c.takeDamage(a.itsDamage());
	a.displayStats();
	c.displayStats();

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	b.attack(c.itsName());
	if (b.itsHealth() > 0 && b.itsEnergy() > 0)
		c.takeDamage(b.itsDamage());
	b.displayStats();
	c.displayStats();

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	c.attack(b.itsName());
	if (c.itsHealth() > 0 && c.itsEnergy() > 0)
		b.takeDamage(c.itsDamage());
	b.displayStats();
	c.displayStats();

	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	b.beRepaired(20);
	b.displayStats();
	b.guardGate();
	c.highFivesGuys();
	return (0);
}
