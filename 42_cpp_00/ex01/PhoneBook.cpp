/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:39:06 by htouil            #+#    #+#             */
/*   Updated: 2023/11/26 18:22:33 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

PhoneBook::PhoneBook(const PhoneBook &src)
{
	(void)src;
	return ;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &src)
{
	(void)src;
	return *this;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::ADD()
{
	if (this->index < 8)
	{
		this->client[index].addcontact();
		this->index++;
	}
	else if (this->index == 8)
	{
		this->index = 0;
		this->ADD();
	}
	return ;
}

void	PhoneBook::SEARCH()
{
	int			i;
	int			num;
	std::string	input;

	i = 0;
	if (this->client[i].value("f").empty() == true)
	{
		std::cout << RED << "The phonebook is empty!" << RESET << std::endl;
		return ;
	}
	std::cout << ".-------------------------------------------." << std::endl;
	std::cout << "|" << GREY << std::setw(10) << "Index" << RESET << "|" 
			<< GREY << std::setw(10) << "First name" << RESET << "|" 
			<< GREY << std::setw(10) << "Last name" << RESET << "|" 
			<< GREY << std::setw(10) << "Phone num" << RESET << "|" << std::endl;
	while (i < 8)
	{
		if (this->client[i].value("f").empty() == false)
		{
			std::cout << ".-------------------------------------------." << std::endl;
			this->client[i].displayinfos(i);
		}
		else
			break ;
		
		i++;
	}
	std::cout << ".-------------------------------------------." << std::endl;
	std::cout << GREEN << "Please enter the index of contact you want to see:" << RESET << std::endl;
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		num = std::atoi(input.c_str());
		if ((num >= 1 && num <= 8) && this->client[num - 1].value("f").empty() == false)
		{
			num -= 1;
			std::cout << "The Contact N." << num + 1 << "'s informations:" << std::endl;
			std::cout << " First name: " << this->client[num].value("f") << std::endl;
			std::cout << " Last name: " << this->client[num].value("l") << std::endl;
			std::cout << " Nickname: " << this->client[num].value("n") << std::endl;
			std::cout << " Phone number: " << this->client[num].value("p") << std::endl;
			std::cout << " Darkest secret: " << this->client[num].value("s") << std::endl;
			break ;
		}
		else
		{
			std::cout << RED << "Invalid index! Please re-enter the index of contact you want to see:" << RESET << std::endl;
			continue ;
		}
	}
	return ;
}

void	PhoneBook::EXIT()
{
	exit(0);
}
