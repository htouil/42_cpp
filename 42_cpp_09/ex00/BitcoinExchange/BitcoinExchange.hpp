/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:57:42 by htouil            #+#    #+#             */
/*   Updated: 2024/07/16 21:36:59 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>
# include <fstream>
# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <ctime>
# include <sstream>

typedef std::vector<std::pair<std::string, double> >	vector; 

vector		getDataBase();
void		parse_display_input(std::ifstream &inputfile, vector database);

#endif
