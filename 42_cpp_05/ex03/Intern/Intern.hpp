/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:36:08 by htouil            #+#    #+#             */
/*   Updated: 2024/05/07 17:17:32 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "../AForm/AForm.hpp"

class Intern
{
	public:
		
				Intern();
				Intern(const Intern &src);
		Intern	&operator=(const Intern &src);
				~Intern();

		AForm	&makeForm(const std::string name, const std::string target);
};

#endif