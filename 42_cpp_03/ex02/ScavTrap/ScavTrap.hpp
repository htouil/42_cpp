/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:37:31 by htouil            #+#    #+#             */
/*   Updated: 2023/12/13 17:22:09 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "../ClapTrap/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
					ScavTrap();
					ScavTrap(std::string s_character);
					ScavTrap(const ScavTrap &src);
		ScavTrap	&operator=(const ScavTrap &src);
					~ScavTrap();

		void		attack(const std::string &target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		void		guardGate();
		
};

#endif
