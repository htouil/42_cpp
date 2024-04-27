/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:53:02 by htouil            #+#    #+#             */
/*   Updated: 2023/12/14 16:49:35 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "../Animal/Animal.hpp"

class Cat : public Animal
{
	public:
				Cat();
				Cat(const Cat &src);
		Cat		&operator=(const Cat &src);
				~Cat();

		void	makeSound();
};

#endif
