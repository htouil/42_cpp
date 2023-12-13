/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:38:23 by htouil            #+#    #+#             */
/*   Updated: 2023/12/13 17:10:04 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << GOLD << "FragTrap default constructor called" << RESET << std::endl;
	this->name = "dumbledore";
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(std::string f_character) : ClapTrap(f_character)
{
	std::cout << GOLD << "FragTrap constructor called" << RESET << std::endl;
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << GOLD << "FragTrap copy constructor called" << RESET << std::endl;
	if (this != &src)
		*this = src;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	std::cout << GOLD << "FragTrap copy assignment ooperator called" << RESET << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->health = src.health;
		this->energy = src.energy;
		this->damage = src.damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << GOLD << "FragTrap default destructor called" << RESET << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->health <= 0)
	{
		std::cout << "FragTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	else if (this->energy == 0)
	{
		std::cout << "FragTrap " << BLUE << this->name << RESET << " has " << RED << "0" << RESET << " energy left!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << BLUE << this->name << RESET << " attacks " << BLUE << target << RESET \
	<< ", dealing " << RED << this->damage << RESET << " points of damage!" << std::endl;
	this->energy--;
	return ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->health <= 0)
	{
		std::cout << "FragTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << BLUE << this->name << RESET << " is hit with " << RED << amount << RESET \
	<< " points of damage" << std::endl;
	this->health -= amount;
	if (this->health <= 0)
	{
		std::cout << "FragTrap " << BLUE << this->name << RESET << " dies!" << std::endl;
		this->health = 0;
	}
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->health <= 0)
	{
		std::cout << "FragTrap " << BLUE << this->name << RESET << " is already dead!" << std::endl;
		return ;
	}
	if (this->health == 100)
	{
		std::cout << "FragTrap " << BLUE << this->name << RESET << " is already at full health!" << std::endl;
		return ;
	}
	else if (this->energy == 0)
	{
		std::cout << "FragTrap " << BLUE << this->name << RESET << " has " << RED << "0" << RESET << " energy left!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << BLUE << this->name << RESET << " heals by " << RED << amount << RESET \
	<< " health points!" << std::endl;
	this->energy--;
	this->health += amount;
	if (this->health > 100)
		this->health = 100;
	return ;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << BLUE << this->name << RESET << " requests the highest high five!" << std::endl;
}
