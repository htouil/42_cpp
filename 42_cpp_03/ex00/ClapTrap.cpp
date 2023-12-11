/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:49:52 by htouil            #+#    #+#             */
/*   Updated: 2023/12/09 17:41:55 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string character) : health(10), energy(10), damage(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	this->name = character;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	if (this != &src)
		*this = src;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	(void)src;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << GREEN << "Default Destructor called" << RESET << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->health <= 0)
	{
		std::cout << "ClapTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	else if (this->energy == 0)
	{
		std::cout << "ClapTrap " << BLUE << this->name << RESET << " has " << RED << "0" << RESET << " energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << BLUE << this->name << RESET << " attacks " << BLUE << target << RESET \
	<< ", dealing " << RED << this->damage << RESET << " points of damage!" << std::endl;
	this->energy--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->health <= 0)
	{
		std::cout << "ClapTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << BLUE << this->name << RESET << " is hit with " << RED << amount << RESET \
	<< " points of damage" << std::endl;
	this->health -= amount;
	if (this->health <= 0)
		std::cout << "ClapTrap " << BLUE << this->name << RESET << " dies!" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->health <= 0)
	{
		std::cout << "ClapTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	if (this->health == 10)
	{
		std::cout << "ClapTrap " << BLUE << this->name << RESET << " is already at full health!" << std::endl;
		return ;
	}
	else if (this->energy == 0)
	{
		std::cout << "ClapTrap " << BLUE << this->name << RESET << " has " << RED << "0" << RESET << " energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << BLUE << this->name << RESET << " heals by " << RED << amount << RESET \
	<< " health points!" << std::endl;
	this->energy--;
	this->health += amount;
	if (this->health > 10)
		this->health = 10;
	return ;
}

void	ClapTrap::setAttackDamage(int atk_damage)
{
	this->damage = atk_damage;
	return ;
}

std::string	ClapTrap::itsName()
{
	return (this->name);
}

int	ClapTrap::itsHealth()
{
	return (this->health);
}

int	ClapTrap::itsEnergy()
{
	return (this->energy);
}

int	ClapTrap::itsDamage()
{
	return (this->damage);
}

void	ClapTrap::displayStats()
{
	std::cout << BLUE << this->name << RESET << " 's stats:" << std::endl;
	std::cout << "  Health points: " << YELLOW << this->health << RESET << std::endl;
	std::cout << "  Energy points: " << YELLOW << this->energy << RESET << std::endl;
	std::cout << "  Attack damage: " << YELLOW << this->damage << RESET << std::endl;
}

