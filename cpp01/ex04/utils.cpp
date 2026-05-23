/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:37:22 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/03 15:05:03 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

void ft_replace(std::string file, std::string s1, std::string s2)
{
	std::ifstream infile(file.c_str());

	if (!infile.is_open())
	{
		std::cerr << "error oppening file" << std::endl;
		exit(1);
	}

	std::string content;
	std::string line;
	while (std::getline(infile, line))
	{
		content += line + "\n";
	}
	infile.close();

	std::string res;
	size_t i = 0;
	size_t found = content.find(s1, i);
	while (found != std::string::npos)
	{
		res += content.substr(i, found - i);
		res += s2;
		i = found + s1.length();
		found = content.find(s1, i);
	}
	res += content.substr(i);

	std::ofstream outfile((file + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "erreur ouverture" << std::endl;
		exit(1);
	}
	outfile << res;
	outfile.close();
	return;
}