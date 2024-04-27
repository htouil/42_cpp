/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:42:24 by htouil            #+#    #+#             */
/*   Updated: 2024/04/27 15:51:25 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

AForm::AForm() : name("chi form"), signature(0), sign_grade(150), exec_grade(150)
{
	std::cout << CRIMSON << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string f_name, int s_grade, int e_grade) : name(f_name), signature(0), sign_grade(s_grade), exec_grade(e_grade)
{
	std::cout << CRIMSON << "AForm constructor called" << RESET << std::endl;
	if (s_grade < 1 || e_grade < 1)
		throw (GradeTooHighException());
	else if (s_grade > 150 || e_grade > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &src) : name(src.name), signature(0), sign_grade(src.sign_grade), exec_grade(src.exec_grade)
{
	std::cout << CRIMSON << "AForm copy constructor called" << RESET << std::endl;
}

AForm	&AForm::operator=(const AForm &src)
{
	std::cout << CRIMSON << "AForm copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->signature = src.signature;
	return (*this);
}

AForm::~AForm()
{
	std::cout << CRIMSON << "AForm destructor called" << RESET << std::endl;
}
