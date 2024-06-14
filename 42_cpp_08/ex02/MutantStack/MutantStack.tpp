/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:26:41 by htouil            #+#    #+#             */
/*   Updated: 2024/06/14 01:42:15 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

MutantStack::MutantStack()
{
	std::cout << MAGENTA << "MutantStack constructor called" << RESET << std::endl;
}

MutantStack::MutantStack(const MutantStack &src)
{
	std::cout << MAGENTA << "MutantStack copy constructor called" << RESET << std::endl;
}

MutantStack	&MutantStack::operator=(const MutantStack &src)
{
	std::cout << MAGENTA << "MutantStack copy assignment operator called" << RESET << std::endl;
}

MutantStack::~MutantStack()
{
	std::cout << MAGENTA << "MutantStack destructor called" << RESET << std::endl;
}


