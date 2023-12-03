/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:16:01 by htouil            #+#    #+#             */
/*   Updated: 2023/12/02 17:31:13 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

int	change(std::string filename, std::string search, std::string replace)
{
	std::ifstream	infile(filename, std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << "Error!" << std::endl << "Unable to open the input file." << std::endl;
		return (1);
	}
	std::ofstream	outfile(std::string(filename) + ".replace", std::ios::out);
	if (!outfile.is_open())
	{
		std::cerr << "Error!" << std::endl << "Unable to open the output file." << std::endl;
		infile.close();
		return (1);
	}
	std::string	line;
	std::string	new_str;
	std::string	final_str;
	size_t		pos;
	size_t		here;

	
	new_str = "\0";
	std::getline(infile, line);
	if (line[0] == '\0')
		return (0);
	else
		new_str += line;
	while (std::getline(infile, line))
	{
		new_str += "\n";
		new_str += line;
	}
	pos = 0;
	final_str = "\0";
	while (pos < new_str.length())
	{
		here = new_str.find(search, pos);
		if (here != std::string::npos)
		{
			final_str += new_str.substr(pos, here - pos);
			final_str += replace;
			pos = here + search.length();
		}
		else
		{
			final_str += new_str.substr(pos);
			break ;
		}
	}
	outfile << final_str;
	infile.close();
	outfile.close();
	return (0);
}

int	main(int ac, char **av)
{
	
	
	if (ac != 4)
	{
		std::cerr << "Error!" << std::endl << "Bad number of parameters inserted." << std::endl << "Usage: ./fcopy <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (change(av[1], av[2], av[3]) == 1)
		return (1);
	return (0);
}