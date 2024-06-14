/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:26:41 by htouil            #+#    #+#             */
/*   Updated: 2024/06/14 02:33:56 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout << MAGENTA << "MutantStack constructor called" << RESET << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src)
{
	std::cout << MAGENTA << "MutantStack copy constructor called" << RESET << std::endl;
	*this = src;
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &src)
{
	std::cout << MAGENTA << "MutantStack copy assignment operator called" << RESET << std::endl;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << MAGENTA << "MutantStack destructor called" << RESET << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin()
{
	return (this->c.begin())
}

template<typename T>
typename MutantStack<T>::cons_iterator	MutantStack<T>::end()
{
	
}
