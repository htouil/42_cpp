/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:05:34 by htouil            #+#    #+#             */
/*   Updated: 2024/05/22 17:43:51 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base/Base.hpp"

int	main()
{
	Base	*x;

	x = generate();
	identify(x);
	identify(*x);
	delete (x);
	return (0);
}