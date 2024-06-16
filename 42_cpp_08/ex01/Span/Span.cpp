/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:38:00 by htouil            #+#    #+#             */
/*   Updated: 2024/06/16 01:44:12 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : size(N) 
{
	std::cout << MAGENTA << "Span constructor called" << RESET << std::endl;
	cntr.reserve(N);
}

Span::Span(const Span &src) : size(src.size)
{
	std::cout << MAGENTA << "Span copy constructor called" << RESET << std::endl;
	std::vector<int>::const_iterator	it;

	for (it = src.cntr.begin(); it != src.cntr.end(); it++)
		this->cntr.push_back(*it);
}

Span	&Span::operator=(const Span &src)
{
	std::cout << MAGENTA << "Span copy assignment operator called" << RESET << std::endl;

	if (this != &src)
	{
		std::vector<int>::const_iterator	it;

		this->size = src.size;
		for (it = src.cntr.begin(); it != src.cntr.end(); it++)
			this->cntr.push_back(*it);
	}
	return (*this);
}

Span::~Span()
{
	std::cout << MAGENTA << "Span destructor called" << RESET << std::endl;
}

std::vector<int>	&Span::getCntr()
{
	return (this->cntr);
}

void	Span::addNumber(int x)
{
	if (this->cntr.size() == this->size)
		throw (std::out_of_range("Span already full, cannot add a number!"));
	this->cntr.push_back(x);
}

void	Span::addMultiNumbers(unsigned int y)
{
	int	num;
	unsigned int	i;

	std::srand(std::time(0));
	for (i = 0; i < y; i++)
	{
		if (this->cntr.size() == this->size)
			throw (std::out_of_range("Span is already full, cannot add a number!"));
		num = (std::rand()) % 101;
		this->cntr.push_back(num);
	}
}

//gotta work with std::adjacent_difference
int	Span::shortestSpan()
{
	std::vector<int>					vec;
	std::vector<int>::const_iterator	min;

	if (this->cntr.size() <= 1)
		throw (std::length_error("Span is too short to calculate!"));
	std::sort(this->cntr.begin(), this->cntr.end());
	vec.resize(this->size);
	std::adjacent_difference(this->cntr.begin(), this->cntr.end(), vec.begin());
	min = std::min_element(++(vec.begin()), vec.end());
	return (*min);
}

int	Span::longestSpan()
{
	std::vector<int>					vec;
	std::vector<int>::const_iterator	min;
	std::vector<int>::const_iterator	max;

	if (this->cntr.size() <= 1)
		throw (std::length_error("Span is too short to calculate!"));
	vec = this->cntr;
	std::sort(vec.begin(), vec.end());
	min = std::min_element(vec.begin(), vec.end());
	max = std::max_element(vec.begin(), vec.end());
	return (*max - *min);
}
