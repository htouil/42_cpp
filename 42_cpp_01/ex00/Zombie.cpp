/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:34:31 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 18:20:40 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::Zombie(const Zombie &src)
{
	(void)src;
	return ;
}

Zombie	&Zombie::operator=(const Zombie &src)
{
	(void)src;
	return (*this);
}

Zombie::~Zombie()
{
	std::cout << "Now go back to your grave, " << CYAN << this->name << RESET << std::endl;
	return ;
}

void	Zombie::announce()
{
	std::cout << "Rise and shine my new zombie!" << std::endl;
	std::cout << "  " << CYAN << this->name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

std::string	&Zombie::value()
{
	return (this->name);
}
