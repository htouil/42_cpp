/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:23:18 by htouil            #+#    #+#             */
/*   Updated: 2024/08/06 18:55:59 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
void	empty_container(T &container)
{
	while (!container.empty())
		container.pop_back();
}

int	parse_input(char **av)
{
	int			i;
	long int	lg;
	char		*endptr;

	i = 1;
	errno = 0;
	while (av[i])
	{
		lg = std::strtol(av[i], &endptr, 10);
		if (errno == ERANGE || lg < 0 || lg > INT_MAX || *endptr != '\0')
		{
			std::cerr << RED << "Error" << std::endl << "incorrect input: " << RESET << "\'" << av[i] << "\'" << std::endl;
			return (1);
		}
		i++;
	}
	return (0);
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
	int	n1, n2, n3;
	int	flag;
	typename T::iterator it;

	flag = 0;
	if (container.size() % 2 != 0)
	{
		flag = 1;
		n3 = container.back();
		container.pop_back();
	}
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
	empty_container(container);
	container.resize(tmp1.size());
	std::copy(tmp1.begin(), tmp1.end(), container.begin());
	if (flag == 1)
	{
		it = std::lower_bound(container.begin(), container.end(), n3);
		container.insert(it, n3);
	}
}

void	sort_n_display(deque &dq, vector &vec)
{
	unsigned int	i;
	std::clock_t	start1, end1;
	std::clock_t	start2, end2;
	double			elapse_time;

	i = -1;
	std::cout << GREEN << "before:  " << RESET;
	while (++i < dq.size())
		std::cout << dq[i] << " ";
	std::cout << std::endl;
	start1 = std::clock();
	sort_numbers(dq);
	end1 = std::clock();
	start2 = std::clock();
	sort_numbers(vec);
	end2 = std::clock();
	i = -1;
	std::cout << BLUE << "after:   " << RESET;
	while (++i < dq.size())
		std::cout << dq[i] << " ";
	std::cout << std::endl;
	elapse_time = (static_cast<double>(end1) - static_cast<double>(start1));
	std::cout << "Time to process a range of " << YELLOW << dq.size() << RESET << " with std::deque : " << CRIMSON << elapse_time << " us" << RESET << std::endl;
	elapse_time = (static_cast<double>(end2) - static_cast<double>(start2));
	std::cout << "Time to process a range of " << YELLOW << dq.size() << RESET << " with std::vector : " << CRIMSON << elapse_time << " us" << RESET << std::endl;
}
