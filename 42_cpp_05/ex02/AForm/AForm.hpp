/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:30:43 by htouil            #+#    #+#             */
/*   Updated: 2024/04/27 15:54:24 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat/Bureaucrat.hpp"

class AForm
{
	protected:
		const std::string	name;
		bool				signature;
		const int			sign_grade;
		const int			exec_grade;

	public:
				AForm();
				AForm(std::string f_name, int s_grade, int e_grade);
				AForm(const AForm &src);
		AForm	&operator=(const AForm &src);
				~AForm();

		virtual void	execute() const = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif