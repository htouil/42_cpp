/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:39:17 by htouil            #+#    #+#             */
/*   Updated: 2023/11/26 17:47:24 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::Contact(const Contact &src)
{
	(void)src;
	return ;
}

Contact &Contact::operator=(const Contact &src)
{
	(void)src;
	return *this;
}

Contact::~Contact()
{
	return ;
}

void	Contact::addcontact()
{
	std::cout << YELLOW << "Please enter the contact's first name: " << RESET << std::endl;
	std::getline(std::cin, this->f_name);
	while (this->f_name.empty())
	{
		if (std::cin.eof())
			exit(0);
		std::cout << RED << "The first name cannot be empty, please re-enter the contact's first name:" << RESET << std::endl;
		std::getline(std::cin, this->f_name);
	}
	std::cout << YELLOW << "Please enter the contact's last name: " << RESET << std::endl;
	std::getline(std::cin, this->l_name);
	while (this->l_name.empty())
	{
		if (std::cin.eof())
			exit(0);
		std::cout << RED << "The last name cannot be empty, please re-enter the contact's last name:" << RESET << std::endl;
		std::getline(std::cin, this->l_name);
	}
	std::cout << YELLOW << "Please enter the contact's nickname: " << RESET << std::endl;
	std::getline(std::cin, this->n_name);
	while (this->n_name.empty())
	{
		if (std::cin.eof())
			exit(0);
		std::cout << RED << "The nickname cannot be empty, please re-enter the contact's nickname:" << RESET << std::endl;
		std::getline(std::cin, this->n_name);
	}
	std::cout << YELLOW << "Please enter the contact's phone number: " << RESET << std::endl;
	std::getline(std::cin, this->phone_num);
	while (this->phone_num.empty())
	{
		if (std::cin.eof())
			exit(0);
		std::cout << RED << "The phone number cannot be empty, please re-enter the contact's phone number:" << RESET << std::endl;
		std::getline(std::cin, this->phone_num);
	}
	std::cout << YELLOW << "Please enter the contact's darkest secret: " << RESET << std::endl;
	std::getline(std::cin, this->secret);
	while (this->secret.empty())
	{
		if (std::cin.eof())
			exit(0);
		std::cout << RED << "The dark secret cannot be empty, please re-enter the contact's dark secret:" << RESET << std::endl;
		std::getline(std::cin, this->secret);
	}
	return ;
}

void	Contact::displayinfos(int index)
{
	std::cout << "|" << std::setw(10) << index + 1 << "|";
	if (this->f_name.length() > 10)
		std::cout << std::setw(9) << this->f_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->f_name << "|";
	if (this->l_name.length() > 10)
		std::cout << std::setw(9) << this->l_name.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->l_name << "|";
	if (this->phone_num.length() > 10)
		std::cout << std::setw(9) << this->phone_num.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->phone_num << "|";
	std::cout << std::endl;
	return ;
}

std::string	Contact::value(std::string var)
{
	if (var == "f")
		return (this->f_name);
	if (var == "l")
		return (this->l_name);
	if (var == "n")
		return (this->n_name);
	if (var == "p")
		return (this->phone_num);
	if (var == "s")
		return (this->secret);
	return (NULL);
}
