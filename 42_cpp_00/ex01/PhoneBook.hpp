/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:39:11 by htouil            #+#    #+#             */
/*   Updated: 2023/11/26 18:30:57 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	client[8];
		int		index;
	public:
		PhoneBook();
		PhoneBook(const PhoneBook &src);
		PhoneBook &operator=(const PhoneBook &src);
		~PhoneBook();
		void	ADD();
		void	SEARCH();
		void	EXIT();
};

#endif
