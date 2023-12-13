/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:36:19 by htouil            #+#    #+#             */
/*   Updated: 2023/12/13 16:36:36 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("voldemort"), health(10), energy(10), damage(0)
{
	std::cout << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string character) : health(10), energy(10), damage(0)
{
	std::cout << GREEN << "ClapTrap constructor called" << RESET << std::endl;
	this->name = character;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << GREEN << "ClapTrap copy constructor called" << RESET << std::endl;
	if (this != &src)
		*this = src;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << GREEN << "ClapTrap copy assignment ooperator called" << RESET << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->health = src.health;
		this->energy = src.energy;
		this->damage = src.damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << GREEN << "ClapTrap default destructor called" << RESET << std::endl;
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
	{
		std::cout << "ClapTrap " << BLUE << this->name << RESET << " dies!" << std::endl;
		this->health = 0;
	}
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
	std::cout << BLUE << this->name << RESET << "'s stats:" << std::endl;
	std::cout << "  Health points: " << YELLOW << this->health << RESET << std::endl;
	std::cout << "  Energy points: " << YELLOW << this->energy << RESET << std::endl;
	std::cout << "  Attack damage: " << YELLOW << this->damage << RESET << std::endl;
}
