/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:34:47 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 19:52:22 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &initWeapon) : nameA(name), WeaponA(initWeapon)
{
	return ;
}

HumanA::HumanA(const HumanA &src) : nameA(src.nameA), WeaponA(src.WeaponA)
{
	return ;
}

HumanA	&HumanA::operator=(const HumanA &src)
{
	(void)src;
	return (*this);
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack()
{
	std::cout << BLUE << this->nameA << RESET << " attacks with their " << RED << this->WeaponA.getType() << RESET << std::endl;
	return ;
}
