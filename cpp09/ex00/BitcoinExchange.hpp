/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:37:17 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/20 18:32:30 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <map>

bool isValidDate(std::string date);
std::string trim(const std::string &str);
void parseInputFile(std::string filename, std::map<std::string, double> &db);
std::map<std::string, double> loadDatabase(std::string filename);

#endif