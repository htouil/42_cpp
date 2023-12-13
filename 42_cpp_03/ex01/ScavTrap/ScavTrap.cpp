/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:47:35 by htouil            #+#    #+#             */
/*   Updated: 2023/12/13 16:58:54 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << MAGENTA << "ScavTrap default constructor called" << RESET << std::endl;
	this->name = "potter";
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(std::string s_character) : ClapTrap(s_character)
{
	std::cout << MAGENTA << "ScavTrap constructor called" << RESET << std::endl;
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << MAGENTA << "ScavTrap copy constructor called" << RESET << std::endl;
	if (this != &src)
		*this = src;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << MAGENTA << "ScavTrap copy assignment ooperator called" << RESET << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->health = src.health;
		this->energy = src.energy;
		this->damage = src.damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << MAGENTA << "ScavTrap default destructor called" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->health <= 0)
	{
		std::cout << "ScavTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	else if (this->energy == 0)
	{
		std::cout << "ScavTrap " << BLUE << this->name << RESET << " has " << RED << "0" << RESET << " energy left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << BLUE << this->name << RESET << " attacks " << BLUE << target << RESET \
	<< ", dealing " << RED << this->damage << RESET << " points of damage!" << std::endl;
	this->energy--;
	return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->health <= 0)
	{
		std::cout << "ScavTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << BLUE << this->name << RESET << " is hit with " << RED << amount << RESET \
	<< " points of damage" << std::endl;
	this->health -= amount;
	if (this->health <= 0)
	{
		std::cout << "ScavTrap " << BLUE << this->name << RESET << " dies!" << std::endl;
		this->health = 0;
	}
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->health <= 0)
	{
		std::cout << "ScavTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	if (this->health == 100)
	{
		std::cout << "ScavTrap " << BLUE << this->name << RESET << " is already at full health!" << std::endl;
		return ;
	}
	else if (this->energy == 0)
	{
		std::cout << "ScavTrap " << BLUE << this->name << RESET << " has " << RED << "0" << RESET << " energy left!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << BLUE << this->name << RESET << " heals by " << RED << amount << RESET \
	<< " health points!" << std::endl;
	this->energy--;
	this->health += amount;
	if (this->health > 100)
		this->health = 100;
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << BLUE << this->name << RESET << " has entered the gate keeper mode!" << std::endl;
}
