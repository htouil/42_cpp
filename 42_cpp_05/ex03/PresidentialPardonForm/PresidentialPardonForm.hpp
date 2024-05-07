/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:53:15 by htouil            #+#    #+#             */
/*   Updated: 2024/05/05 14:56:50 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "../AForm/AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
	
							PresidentialPardonForm(const std::string target);
							PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
							~PresidentialPardonForm();

	void	beSigned(Bureaucrat &signer);
	void	execute(const Bureaucrat &executor) const;
};

#endif