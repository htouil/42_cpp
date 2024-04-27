/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:42:42 by htouil            #+#    #+#             */
/*   Updated: 2023/12/16 19:30:32 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "../Animal/Animal.hpp"

class Brain
{
	private:
		std::string	ideas[100];
	public:
					Brain();
					Brain(const Brain &src);
		Brain		&operator=(const Brain &src);
					~Brain();

		std::string	getIdea(int index);
		void		setIdea(int index, std::string idea);
};

#endif
