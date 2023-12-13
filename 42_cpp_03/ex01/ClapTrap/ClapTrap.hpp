/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:47:03 by htouil            #+#    #+#             */
/*   Updated: 2023/12/13 16:42:25 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

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

class ClapTrap
{
	protected:
		std::string	name;
		int			health;
		int			energy;
		int			damage;
	public:
						ClapTrap();
						ClapTrap(std::string c_character);
						ClapTrap(const ClapTrap &src);
		ClapTrap		&operator=(const ClapTrap &src);
		virtual			~ClapTrap();

		void			attack(const std::string &target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		void			setAttackDamage(int atk_damage);
		std::string		itsName();
		int				itsHealth();
		int				itsEnergy();
		int				itsDamage();
		void			displayStats();
};

#endif
