/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:53:07 by htouil            #+#    #+#             */
/*   Updated: 2024/05/06 14:13:38 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "../AForm/AForm.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << GOLD << "PresidentialPardonForm constructor called" << RESET << std::endl;
	this->signature = 0;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	std::cout << GOLD << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
	this->signature = src.signature;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << GOLD << "PresidentialPardonForm copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->signature = src.signature;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GOLD << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

void	PresidentialPardonForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->sign_grade)
		throw (GradeTooLowException());
	else
		this->signature = 1;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->signature == 0)
	{
		throw (FormNotSigned());
		return ;
	}
	if (executor.getGrade() > this->exec_grade)
	{
		throw (GradeTooLowException());
		return ;
	}
	std::cout << AQUA << this->_target << RESET << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}