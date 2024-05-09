/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:30:43 by htouil            #+#    #+#             */
/*   Updated: 2024/05/09 16:49:32 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
// # include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

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
		AForm		&operator=(const AForm &src);
		virtual		~AForm();

		std::string		getName();
		bool			getSign();
		int				getSignGrade();
		int				getExecGrade();
		virtual void	beSigned(Bureaucrat &signer) = 0;
		virtual void	execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

#endif