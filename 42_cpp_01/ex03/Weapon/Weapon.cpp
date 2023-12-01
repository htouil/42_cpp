/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:12:48 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 19:17:24 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string initWeapon) : type(initWeapon)
{
	return ;
}

Weapon::Weapon(const Weapon &src)
{
	(void)src;
	return ;
}

Weapon	&Weapon::operator=(const Weapon &src)
{
	(void)src;
	return (*this);
}

Weapon::~Weapon()
{
	return ;
}

const std::string	&Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
