/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:43:36 by htouil            #+#    #+#             */
/*   Updated: 2023/12/15 17:38:36 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "../WrongAnimal/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
					WrongCat();
					WrongCat(const WrongCat &src);
		WrongCat	&operator=(const WrongCat &src);
					~WrongCat();

		void		makeSound();
};

#endif
