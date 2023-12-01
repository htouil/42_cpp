/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:39:37 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 18:21:43 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

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

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(const Zombie &src);
		Zombie		&operator=(const Zombie &src);
		~Zombie();

		void		announce();
		std::string	&value();
};

Zombie	*zombieHorde(int N, std::string name);

#endif