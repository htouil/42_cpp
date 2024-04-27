/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:43:47 by htouil            #+#    #+#             */
/*   Updated: 2023/12/17 00:43:48 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "../Brain/Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*c_brain;
	public:
				Cat();
				Cat(const Cat &src);
		Cat		&operator=(const Cat &src);
				~Cat();

		void	makeSound();
		Brain	&accessBrain();
};

#endif
