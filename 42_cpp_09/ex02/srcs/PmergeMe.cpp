/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:23:18 by htouil            #+#    #+#             */
/*   Updated: 2024/08/03 20:18:37 by htouil           ###   ########.fr       */
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

template<typename T>
void	arrange_numbers(T &container1, T &container2)
{
	typename T::iterator it;

	std::cout << "SALAM" << std::endl;
	std::cout << "tmp1:  " << RESET;
	for (it = container1.begin(); it != container1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "tmp2:  " << RESET;
	for (it = container2.begin(); it != container2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	if (container2.size() > 0)
	{
		it = std::lower_bound(container1.begin(), container1.end(), container2[0]);
		container1.insert(it, container2[0]);
		container2.erase(container2.begin());
		arrange_numbers(container1, container2);
	}
}

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
		tmp2.push_back(container[n2]);
		i++;
	}
	std::sort(tmp1.begin(), tmp1.end());
	std::sort(tmp2.begin(), tmp2.end());
	arrange_numbers(tmp1, tmp2);
	// typename T::iterator it;
	
	// std::cout << GREEN << "tmp1:  " << RESET;
	// for (it = tmp1.begin(); it != tmp1.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << GREEN << "tmp2:  " << RESET;
	// for (it = tmp2.begin(); it != tmp2.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// tmp3.resize(tmp1.size() + tmp2.size());
	// std::merge(tmp1.begin(), tmp1.end(), tmp2.begin(), tmp2.end(), tmp3.begin());
	// std::cout << GREEN << "tmp3:  " << RESET;
	// for (it = tmp3.begin(); it != tmp3.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
}

void	sort_n_display(deque &dq, vector &vec)
{
	unsigned int	i;
	(void)vec;

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
	// sort_numbers(vec);
	i = -1;
	std::cout << BLUE << "after:   " << RESET;
	while (++i < dq.size())
		std::cout << dq[i] << " ";
	std::cout << std::endl;
}
