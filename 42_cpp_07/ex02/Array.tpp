/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:19:45 by htouil            #+#    #+#             */
/*   Updated: 2024/06/04 20:02:15 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
unsigned int	Array<T>::size()
{
	return (this->len);
}

template<typename T>
Array<T>::Array()
{
	std::cout << GREEN << "Array default constructor called" << RESET << std::endl;
	this->arr = NULL;
	this->len = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	unsigned int	i;

	std::cout << GREEN << "Array constructor called" << RESET << std::endl;
	if (n == 0)
	{
		this->arr = NULL;
		this->len = 0;
	}
	else if (n > 0)
	{
		this->arr = new T[n];
		for (i = 0; i < n; i++)
			this->arr[i] = 72;
		this->len = n;
	}
	return ;
}

template<typename T>
Array<T>::Array(const Array &src)
{
	std::cout << GREEN << "Array copy constructor called" << RESET << std::endl;
	if (src.arr == NULL)
		this->arr = NULL;
	else
	{
		unsigned int	i;

		this->arr = new T[src.len];
		for (i = 0; i < src.len; i++)
			this->arr[i] = src.arr[i];
		this->len = src.len;
	}
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &src)
{
	std::cout << GREEN << "Array copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		if (this->arr)
			delete[] this->arr;
		if (src.arr == NULL)
			this->arr = NULL;
		else
		{
			unsigned int	i;

			this->arr = new T[src.len];
			for (i = 0; i < src.len; i++)
				this->arr[i] = src.arr[i];
			this->len = src.len;
		}
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	std::cout << GREEN << "Array destructor called" << RESET << std::endl;
	if (this->arr != NULL)
		delete[] this->arr;
}

template<typename T>
T	*Array<T>::getArr()
{
	return (this->arr);
}

template<typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("The index is out of the array bounds!");
}

template<typename T>
const char	*Array<T>::EmptyArrayException::what() const throw()
{
	return ("The array is empty!");
}

template<typename T>
T	&Array<T>::operator[](unsigned int i)
{
	if (this->arr == NULL)
		throw (EmptyArrayException());
	if (i >= this->len)
		throw (OutOfBoundsException());
	return (this->arr[i]);
}
