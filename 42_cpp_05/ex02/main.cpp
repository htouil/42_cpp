/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:25:09 by htouil            #+#    #+#             */
/*   Updated: 2024/04/26 23:55:40 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"

int	main()
{
	{
		std::cout << YELLOW << "------TEST 1------" << RESET << std::endl;
		ShrubberyCreationForm	a("home");

		a.execute();
	}
	
	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
	}
}