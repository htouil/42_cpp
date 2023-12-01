/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:40:36 by htouil            #+#    #+#             */
/*   Updated: 2023/11/30 17:53:22 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define GREY    "\033[90m"
#define WHITE   "\033[37m"

int	main()
{
	std::string	speech;
	std::string	*stringPTR;
	std::string	&stringREF = speech;

	speech = "HI THIS IS BRAIN";
	stringPTR = &speech;
	std::cout << CYAN << "Memory addresses of:" << RESET << std::endl;
	std::cout << GREEN << "  The string: " << RESET << &speech << std::endl;
	std::cout << GREEN << "  The pointer: " << RESET << stringPTR << std::endl;
	std::cout << GREEN << "  The reference: " << RESET << &stringREF << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << CYAN << "Value of:" << RESET << std::endl;
	std::cout << GREEN << "  The string: " << RESET << speech << std::endl;
	std::cout << GREEN << "  The pointer: " << RESET << *stringPTR << std::endl;
	std::cout << GREEN << "  The reference: " << RESET << stringREF << std::endl << std::endl;
	return (0);
}