/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:09:13 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 19:32:30 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define GREY    "\033[90m"
# define WHITE   "\033[37m"

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(const std::string initWeapon);
		Weapon(const Weapon &src);
		Weapon	&operator=(const Weapon &src);
		~Weapon();

		const std::string	&getType();
		void				setType(std::string newType);
};

#endif