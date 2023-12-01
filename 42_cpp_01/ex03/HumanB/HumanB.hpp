/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:35:42 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 20:27:21 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "../Weapon/Weapon.hpp"

class HumanB
{
	private:
		std::string	nameB;
		Weapon		*WeaponB;
	public:
		HumanB(std::string name);
		HumanB(const HumanB &src);
		HumanB	&operator=(const HumanB &src);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &newWeapon);
};

#endif