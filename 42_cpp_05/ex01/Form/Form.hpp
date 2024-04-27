/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:38:49 by htouil            #+#    #+#             */
/*   Updated: 2024/04/27 15:32:29 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				signature;
		const int			sign_grade;
		const int			exec_grade;
	public:
					Form();
					Form(std::string f_name, int s_grade, int e_grade);
					Form(const Form &src);
		Form		&operator=(const Form &src);
					~Form();

		std::string	getName();
		bool		getSign();
		int			getSignGrade();
		int			getExecGrade();
		void		beSigned(Bureaucrat &src);
		
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Form &src);

#endif
