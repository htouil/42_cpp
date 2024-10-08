/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:35:59 by htouil            #+#    #+#             */
/*   Updated: 2024/05/09 17:53:43 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern  &src)
{
	(void)src;
	std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
}

Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << GREEN << "Intern copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << GREEN << "Intern destructor called" << RESET << std::endl;
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	int			i;
	AForm		*form[4] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target), nullptr};
	std::string	form_name[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	std::cout << "Intern creates " << PINK << name << RESET << std::endl;
	for (i = 0; i < 3; i++)
	{
		if (name != form_name[i])
			delete (form[i]);
	}
	for (i = 0; i < 3; i++)
	{
		if (name == form_name[i])
			return (form[i]);
	}
	std::cout << "Intern couldn't create a form with the name of " << GREEN << name << RESET << ", because it doesn't exist." << std::endl;
	return (form[3]);
}
