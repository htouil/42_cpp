/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:22:09 by htouil            #+#    #+#             */
/*   Updated: 2024/04/25 17:02:20 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("new guy"), grade(150)
{
	std::cout << INDIGO << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string b_name, int b_grade) : name(b_name)
{
	std::cout << INDIGO << "Bureaucrat constructor called" << RESET << std::endl;
	if (b_grade < 1)
		throw (GradeTooHighException());
	else if (b_grade > 150)
		throw (GradeTooLowException());
	this->grade = b_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name)
{
	std::cout << "Bureaucrat copy constructor called" << RESET << std::endl;
	this->grade = src.grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << INDIGO << "Bureaucrat copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->grade = src.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << INDIGO << "Bureaucrat destructor called" << RESET << std::endl;
}

void	Bureaucrat::setGrade(int s_grade)
{
	if (s_grade < 1)
		throw (GradeTooHighException());
	else if (s_grade > 150)
		throw (GradeTooLowException());
	this->grade = s_grade;
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw (GradeTooHighException());
	this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw (GradeTooLowException());
	this->grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade you have set is too HIGH!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade you have set is too LOW!");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << GREEN << src.getName() << RESET << ", bureaucrat grade " << CYAN << src.getGrade() << RESET;
	return (out);
}
