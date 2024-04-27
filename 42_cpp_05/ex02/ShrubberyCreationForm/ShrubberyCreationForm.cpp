/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:25:09 by htouil            #+#    #+#             */
/*   Updated: 2024/04/27 15:53:47 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "../AForm/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(target, 145, 137)
{
	std::cout << BROWN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
	this->signature = 0;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	std::cout << BROWN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << BROWN << "ShrubberyCreationForm copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->signature = src.signature;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BROWN << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

std::string	ascii_tree() 
{
	std::string	tree;

	tree =
		"        /\\\n"
		"       /  \\\n"
		"      /    \\\n"
		"     /      \\\n"
		"    /        \\\n"
		"   /----------\\\n"
		"  /   CHAJARA  \\\n"
		" /--------------\\\n"
		"/________________\\\n"
		"        | |\n"
		"        | |\n"
		"        | |\n"
		"        | |\n";
	return (tree);
}

void	ShrubberyCreationForm::execute() const
{
	std::ofstream	outfile(this->name + "_shrubbery", std::ios::out);
	std::string		tree;

	if (!outfile.is_open())
	{
		std::cerr << "Error!" << std::endl << "Unable to open the output file." << std::endl;
		return ;
	}
	tree = ascii_tree();
	outfile << tree;
	outfile.close();
}
