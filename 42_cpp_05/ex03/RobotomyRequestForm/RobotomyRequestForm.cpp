/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:56:20 by htouil            #+#    #+#             */
/*   Updated: 2024/05/07 17:06:01 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "../AForm/AForm.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request", 72, 45), _target(target)
{
	std::cout << SALMON << "RobotomyRequestForm constructor called" << RESET << std::endl;
	this->signature = 0;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
	std::cout << SALMON << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << SALMON << "RobotomyRequestForm copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->signature = src.signature;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << SALMON << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

void	RobotomyRequestForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->sign_grade)
		throw (GradeTooLowException());
	else
		this->signature = 1;
}

int	half_chance()
{
	int	i;

	srand(static_cast<unsigned int>(std::time(nullptr)));
	i = rand() % 2;
	return (i);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	int	i;

	if (this->signature == 0)
	{
		throw (FormNotSigned());
		return ;
	}
	else if (executor.getGrade() > this->exec_grade)
	{
		throw (GradeTooLowException());
		return ;
	}
	std::cout << CORAL << "WHIIRRRRRRRRR!" << RESET << std::endl;
	
	i = half_chance(); // get a better randomizing function
	// std::cout << i << std::endl;
	if (i == 0)
		std::cout << "The robotomy has " << RED <<  "failed" << RESET << std::endl;
	else if (i == 1)
		std::cout << CYAN << this->_target << RESET << " has been robotomized successfully." << std::endl;
}
