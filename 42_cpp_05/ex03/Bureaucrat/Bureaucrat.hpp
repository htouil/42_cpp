/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:27:26 by htouil            #+#    #+#             */
/*   Updated: 2024/04/27 19:03:29 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

# define RESET       "\033[0m"
# define RED         "\033[31m"
# define GREEN       "\033[32m"
# define YELLOW      "\033[33m"
# define BLUE        "\033[34m"
# define MAGENTA     "\033[35m"
# define CYAN        "\033[36m"
# define GREY        "\033[90m"
# define WHITE       "\033[37m"
# define GOLD        "\033[38;5;178m"
# define ORANGE      "\033[38;5;202m"
# define PINK        "\033[38;5;206m"
# define PURPLE      "\033[38;5;141m"
# define BROWN       "\033[38;5;94m"
# define BEIGE       "\033[38;5;224m"
# define OLIVE_GREEN "\033[38;5;58m"
# define TEAL        "\033[38;5;30m"
# define AQUA        "\033[38;5;51m"
# define MAROON      "\033[38;5;52m"
# define CRIMSON     "\033[38;5;160m"
# define CORAL       "\033[38;5;203m"
# define SALMON      "\033[38;5;209m"
# define TURQUOISE   "\033[38;5;45m"
# define INDIGO      "\033[38;5;54m"

class AForm;

class Bureaucrat
{
	protected:
		const std::string	name;
		int					grade;
	public:
						Bureaucrat();
						Bureaucrat(std::string b_name, int b_grade);
						Bureaucrat(const Bureaucrat &src);
		Bureaucrat		&operator=(const Bureaucrat &src);
						~Bureaucrat();

		void		setGrade(int s_grade);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &src);
		void		executeForm(AForm &src);

		class GradeTooHighException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif
