/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:38:56 by htouil            #+#    #+#             */
/*   Updated: 2024/05/02 17:31:18 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

Form::Form() : name("chi form"), signature(0), sign_grade(150), exec_grade(150)
{
	std::cout << CRIMSON << "Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string f_name, int s_grade, int e_grade) : name(f_name), signature(0), sign_grade(s_grade), exec_grade(e_grade)
{
	std::cout << CRIMSON << "Form constructor called" << RESET << std::endl;
	if (s_grade < 1 || e_grade < 1)
		throw (GradeTooHighException());
	else if (s_grade > 150 || e_grade > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &src) : name(src.name), signature(0), sign_grade(src.sign_grade), exec_grade(src.exec_grade)
{
	std::cout << CRIMSON << "Form copy constructor called" << RESET << std::endl;
}

Form	&Form::operator=(const Form &src)
{
	std::cout << CRIMSON << "Form copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->signature = src.signature;
	return (*this);
}

Form::~Form()
{
	std::cout << CRIMSON << "Form destructor called" << RESET << std::endl;
}

std::string	Form::getName()
{
	return (this->name);
}

bool	Form::getSign()
{
	return (this->signature);
}

int	Form::getSignGrade()
{
	return (this->sign_grade);
}

int	Form::getExecGrade()
{
	return (this->exec_grade);
}

void	Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->sign_grade)
		throw (GradeTooLowException());
	else
		this->signature = 1;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too HIGH!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too LOW!");
}

std::ostream	&operator<<(std::ostream &out, Form &src)
{
	if (src.getSign() == 0)
		out << "The form " << GREEN << src.getName() << RESET << " of sign grade " << CYAN << src.getSignGrade() << RESET << " and of execute grade " << CRIMSON << src.getExecGrade() << GOLD << " is not signed.";
	else
		out << "The form " << GREEN << src.getName() << RESET << " of sign grade " << CYAN << src.getSignGrade() << RESET << " and of execute grade " << CRIMSON << src.getExecGrade() << GOLD << " is signed.";
	return (out);
}
