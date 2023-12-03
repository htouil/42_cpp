/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:32:43 by htouil            #+#    #+#             */
/*   Updated: 2023/12/02 16:29:59 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::Harl(const Harl &src)
{
	(void)src;
	return ;
}

Harl	&Harl::operator=(const Harl &src)
{
	(void)src;
	return (*this);
}
Harl::~Harl()
{
	return ;
}

void	Harl::debug()
{
	std::cout << CYAN << "\"DEBUG\" level: " << RESET << std::endl;
	std::cout << "  I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info()
{
	std::cout << CYAN << "\"INFO\" level: " << RESET << std::endl;
	std::cout << "  I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning()
{
	std::cout << CYAN << "\"WARNING\" level: " << RESET << std::endl;
	std::cout << "  I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error()
{
	std::cout << CYAN << "\"ERROR\" level: " << RESET << std::endl;
	std::cout << "  This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	int			i;
	void		(Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*func[i])();
			break ;
		}
	}
	return ;
}