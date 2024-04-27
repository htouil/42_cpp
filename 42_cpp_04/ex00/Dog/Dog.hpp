/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:52:29 by htouil            #+#    #+#             */
/*   Updated: 2023/12/14 16:49:46 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "../Cat/Cat.hpp"

class Dog : public Animal
{
	public:
				Dog();
				Dog(const Dog &src);
		Dog		&operator=(const Dog &src);
				~Dog();

		void	makeSound();
};

#endif
