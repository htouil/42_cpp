/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:26:41 by htouil            #+#    #+#             */
/*   Updated: 2024/06/21 20:32:24 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout << MAGENTA << "MutantStack constructor called" << RESET << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) : std::stack<T>(src)
{
	std::cout << MAGENTA << "MutantStack copy constructor called" << RESET << std::endl;
	*this = src;
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &src)
{
	std::cout << MAGENTA << "MutantStack copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->c = src.c;
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
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const
{
	return (this->c.rend());
}
