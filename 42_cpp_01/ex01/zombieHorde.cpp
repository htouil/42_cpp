/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:40:26 by htouil            #+#    #+#             */
/*   Updated: 2023/12/02 17:03:22 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie;
	int		i;
	
	zombie = NULL;
	if (N > 0)
	{
		zombie = new Zombie[N];
		for (i = 0; i < N; i++)
			zombie[i].value() = name;
	}
	return (zombie);
}
