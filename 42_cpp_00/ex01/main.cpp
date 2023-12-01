/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:38:56 by htouil            #+#    #+#             */
/*   Updated: 2023/11/26 17:48:57 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	the_book;
	std::string	command;

	while (1)
	{
		std::cout << BLUE << "Please enter a command: " << RESET << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			exit (0);
		if (command == "ADD")
			the_book.ADD();
		else if (command == "SEARCH")
			the_book.SEARCH();
		else if (command == "EXIT")
			the_book.EXIT();
		else
			std::cout << RED << "Invalid command! Please re-enter a command: " << RESET << std::endl;
	}
	return (0);
}
