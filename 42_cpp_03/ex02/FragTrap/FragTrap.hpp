/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:38:15 by htouil            #+#    #+#             */
/*   Updated: 2023/12/13 17:23:02 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "../ScavTrap/ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
					FragTrap();
					FragTrap(std::string f_character);
					FragTrap(const FragTrap &src);
		FragTrap	&operator=(const FragTrap &src);
					~FragTrap();

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		highFivesGuys();
};

#endif