/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:41:05 by htouil            #+#    #+#             */
/*   Updated: 2023/12/02 17:05:37 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int		i;

	horde = zombieHorde(3, "Oars");
	if (horde == NULL)
		exit (0);
	for (i = 0; i < 3; i++)
		horde[i].announce();
	std::cout << "------------------------------------" << std::endl;
	delete[] horde;
	return (0);
}
