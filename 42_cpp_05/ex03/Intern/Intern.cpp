/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:35:59 by htouil            #+#    #+#             */
/*   Updated: 2024/05/07 17:38:32 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "../AForm/AForm.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern  &src)
{
	std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
}

Intern	&Intern::operator=(const Intern &src)
{
	std::cout << GREEN << "Inter copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << GREEN << "Inter destructor called" << RESET << std::endl;
}

AForm	&Intern::makeForm(const std::string name, const std::string target)
{
	std::cout << "Intern creates " << PINK << name << RESET << std::endl;
	
}