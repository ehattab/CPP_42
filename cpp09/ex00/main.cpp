/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:36:32 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/20 19:24:41 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	std::map<std::string, double> db = loadDatabase("data.csv");
	if (db.empty())
		return 1;

	parseInputFile(argv[1], db);
	return 0;
}