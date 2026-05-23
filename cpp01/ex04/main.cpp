/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:28:54 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/03 15:04:35 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

void ft_replace(std::string file, std::string s1, std::string s2);

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./ex04 <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::ifstream original(av[1]);
	std::string line;
	std::cout << "--- ORIGINAL ---" << std::endl;
	while (std::getline(original, line))
		std::cout << line << std::endl;
	original.close();

	ft_replace(av[1], av[2], av[3]);

	std::string outname = std::string(av[1]) + ".replace";
	std::ifstream replaced(outname.c_str());
	std::cout << "--- REPLACED ---" << std::endl;
	while (std::getline(replaced, line))
		std::cout << line << std::endl;
	replaced.close();

	return (0);
}