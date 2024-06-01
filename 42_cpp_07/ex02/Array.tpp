/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:19:45 by htouil            #+#    #+#             */
/*   Updated: 2024/06/01 20:32:03 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
unsigned int	Array<T>::size()
{
	unsigned int	i;

	i = 0;
	if (this->arr == NULL)
		return (i);
	while (this->arr[i])
		i++;
	return (i);
}

template<typename T>
Array<T>::Array()
{
	std::cout << MAROON << "Array default constructor called" << RESET << std::endl;
	this->arr = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	unsigned int	i;

	std::cout << MAROON << "Array constructor called" << RESET << std::endl;
	this->arr = NULL;
	if (n > 0)
	{
		this->arr = new T[n];
		for (i = 0; i < n; i++)
			this->arr[i] = 72;
	}
}

template<typename T>
Array<T>::Array(const Array &src)
{
	std::cout << MAROON << "Array copy constructor called" << RESET << std::endl;
	if (src.arr == NULL)
		this->arr = NULL;
	else
	{
		unsigned int	i;
		unsigned int	n;

		n = src.size();
		this->arr = new T[n];
		for (i = 0; i < n; i++)
			this->arr[i] = src.arr[i];
	}
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &src)
{
	std::cout << MAROON << "Array copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		if (this->arr != NULL)
			delete[] this->arr;
		if (src.arr == NULL)
			this->arr = NULL;
		else
		{
			unsigned int	i;
			unsigned int	n;

			n = src.size();
			this->arr = new T[n];
			for (i = 0; i < n; i++)
				this->arr[i] = src.arr[i];
		}
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	std::cout << MAROON << "Array destructor called" << RESET << std::endl;
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
	return ("This index is out of the array bounds!");
}

template<typename T>
T	&Array<T>::operator[](int i)
{
	if (i < 0 || i > this->getArr())
		throw (OutOfBoundsException());
	return (this->arr[i]);
}
