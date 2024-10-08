/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:28:53 by htouil            #+#    #+#             */
/*   Updated: 2023/12/02 16:56:06 by htouil           ###   ########.fr       */
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
		Zombie(std::string newName);
		Zombie(const Zombie &src);
		Zombie		&operator=(const Zombie &src);
		~Zombie();

		void		announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif