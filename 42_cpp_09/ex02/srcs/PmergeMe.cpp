/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:23:18 by htouil            #+#    #+#             */
/*   Updated: 2024/08/01 21:55:52 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	parse_input(char **av)
{
	int			i;
	long int	lg;
	char		*endptr;

	i = 1;
	errno = 0;
	while (av[i])
	{
		lg = std::strtol(av[i], &endptr, 10);
		// std::cout << lg << std::endl;
		// std::cout << errno << std::endl;
		// std::cout << *endptr << std::endl;
		if (errno == ERANGE || lg < 0 || lg > INT_MAX || *endptr != '\0')
		{
			std::cerr << RED << "Error" << std::endl << "incorrect input: " << RESET << "\'" << av[i] << "\'" << std::endl;
			exit(1);
		}
		i++;
	}
}

void	get_numbers(char **av, deque &dq, vector &vec)
{
	int		i;

	i = 1;
	while(av[i])
	{
		dq.push_back(std::atoi(av[i]));
		vec.push_back(std::atoi(av[i]));
		i++;
	}
}

// template<typename T>
// void	arrange_numbers(T &container, int i, int grps)
// {
// 	if (i <= grps)
// 	{
		
// 	}
// }

template<typename T>
void	sort_numbers(T &container)
{
	T	tmp1, tmp2, tmp3;
	int	grps;
	int	i;
	int	n1, n2;

	grps = container.size() / 2;
	i = 1;
	while (i <= grps)
	{
		n1 = (2 * i) - 2;
		n2 = (2 * i) - 1;
		if (container[n1] > container[n2])
			std::swap(container[n1], container[n2]);
		tmp1.push_back(container[n1]);
		tmp2.push_bck(container[n2]);
		i++;
	}
	std::sort(tmp1.begin(), tmp1.end());
	std::sort(tmp2.begin(), tmp2.end());
	tmp3 = std::merge();
	i = 0;
	// arrange_numbers(container, i + 1, grps);
}

void	sort_n_display(deque &dq, vector &vec)
{
	unsigned int	i;

	i = -1;
	std::cout << GREEN << "before:  " << RESET;
	while (++i < dq.size())
		std::cout << dq[i] << " ";
	std::cout << std::endl;
	//start time
	sort_numbers(dq);
	//end time
	//display time
	//start time
	sort_numbers(vec);
	i = -1;
	std::cout << BLUE << "after:   " << RESET;
	while (++i < dq.size())
		std::cout << dq[i] << " ";
	std::cout << std::endl;
}
