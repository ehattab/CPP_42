/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:37:17 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/20 18:52:58 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, (last - first + 1));
}

bool isValidDate(std::string date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[2] = 29;
	if (day > daysInMonth[month])
		return false;
	return true;
}

std::map<std::string, double> loadDatabase(std::string filename)
{
	std::map<std::string, double> db;
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return db;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, commaPos));
		std::string rateStr = trim(line.substr(commaPos + 1));

		double rate;
		std::stringstream ss(rateStr);
		ss >> rate;

		if (!ss.fail() && ss.eof())
		{
			db[date] = rate;
		}
	}
	return db;
}

void parseInputFile(std::string filename, std::map<std::string, double> &db)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << (date.empty() ? line : date) << std::endl;
			continue;
		}

		if (valueStr.empty())
		{
			std::cerr << "Error: missing value" << std::endl;
			continue;
		}

		double value;
		std::stringstream ss(valueStr);
		ss >> value;

		if (ss.fail() || !ss.eof())
		{
			std::cerr << "Error: invalid number format" << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number" << std::endl;
			continue;
		}

		std::map<std::string, double>::iterator it = db.lower_bound(date);

		if (it == db.end() || it->first != date)
		{
			if (it == db.begin())
			{
				std::cerr << "Error: date too early, no data available" << std::endl;
				continue;
			}
			it--;
		}

		double result = value * it->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}