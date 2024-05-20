/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:54:39 by htouil            #+#    #+#             */
/*   Updated: 2024/05/20 21:50:15 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	x;

	x = reinterpret_cast<uintptr_t>(ptr);
	return (x);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*y;

	y = reinterpret_cast<Data*>(raw);
	return (y);
}
