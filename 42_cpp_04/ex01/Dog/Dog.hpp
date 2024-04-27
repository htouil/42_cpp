/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:40:00 by htouil            #+#    #+#             */
/*   Updated: 2023/12/16 19:49:30 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "../Cat/Cat.hpp"

class Dog : public Animal
{
	private:
		Brain	*d_brain;
	public:
				Dog();
				Dog(const Dog &src);
		Dog		&operator=(const Dog &src);
				~Dog();

		void	makeSound();
		Brain	&accessBrain();
};

#endif
