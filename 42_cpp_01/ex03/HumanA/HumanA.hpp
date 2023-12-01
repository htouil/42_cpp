/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:32:49 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 19:51:23 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "../Weapon/Weapon.hpp"

class HumanA
{
	private:
		std::string	nameA;
		Weapon		&WeaponA;
	public:
		HumanA(std::string name, Weapon &initWeapon);
		HumanA(const HumanA &src);
		HumanA	&operator=(const HumanA &src);
		~HumanA();

		void	attack();
};

#endif