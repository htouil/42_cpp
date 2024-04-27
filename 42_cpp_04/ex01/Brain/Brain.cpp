/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:42:36 by htouil            #+#    #+#             */
/*   Updated: 2023/12/16 19:31:57 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREY << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << GREY << "Brain default copy constructor called" << RESET << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &src)
{
	int	i;

	std::cout << GREY << "Brain copy assignment operator called" << RESET << std::endl;
	for (i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << GREY << "Brain default destructor called" << RESET << std::endl;
}

std::string	Brain::getIdea(int index)
{
	return (this->ideas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	this->ideas[index] = idea;
}
