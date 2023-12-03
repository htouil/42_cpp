/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:36:18 by htouil            #+#    #+#             */
/*   Updated: 2023/12/02 17:21:43 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : nameB(name)
{
	this->WeaponB = NULL;
	return ;
}

HumanB::HumanB(const HumanB &src) : nameB(src.nameB)
{
	(void)src;
	return ;
}

HumanB	&HumanB::operator=(const HumanB &src)
{
	(void)src;
	return (*this);
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack()
{
	std::cout << BLUE << this->nameB << RESET << " attacks with their " << RED << this->WeaponB->getType() << RESET << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->WeaponB = &newWeapon;
	return ;
}
