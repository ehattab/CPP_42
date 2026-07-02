/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:19:44 by ehattab           #+#    #+#             */
/*   Updated: 2026/06/29 16:58:05 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

bool isInt(std::string const &value)
{
	size_t i = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;
	if (i == value.length())
		return false;
	for (; i < value.length(); i++)
	{
		if (!std::isdigit(value[i]))
			return false;
	}
	return true;
}

bool isChar(std::string const &value)
{
	if (value.length() == 1 && !std::isdigit(value[0]) && std::isprint(value[0]))
		return true;
	return false;
}

bool isDouble(std::string const &value)
{
	size_t i = 0;
	int dotCount = 0;
	int digitCount = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;
	for (; i < value.length(); i++)
	{
		if (value[i] == '.')
		{
			dotCount++;
		}
		else if (std::isdigit(value[i]))
		{
			digitCount++;
		}
		else
		{
			return false;
		}
	}
	if (dotCount == 1 && digitCount > 0)
		return true;
	return false;
}

bool isFloat(std::string const &value)
{
	if (value[value.length() - 1] != 'f')
		return false;

	size_t i = 0;
	int dotCount = 0;
	int digitCount = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;
	for (; i < value.length() - 1; i++)
	{
		if (value[i] == '.')
		{
			dotCount++;
		}
		else if (std::isdigit(value[i]))
		{
			digitCount++;
		}
		else
		{
			return false;
		}
	}
	if (dotCount == 1 && digitCount > 0)
		return true;
	return false;
}

static e_type getType(std::string const &value)
{
	if (value == "nan" || value == "+inf" || value == "-inf")
		return TYPE_DOUBLE;
	else if (value == "nanf" || value == "+inff" || value == "-inff")
		return TYPE_FLOAT;

	if (isChar(value))
		return TYPE_CHAR;
	if (isInt(value))
		return TYPE_INT;
	if (isDouble(value))
		return TYPE_DOUBLE;
	if (isFloat(value))
		return TYPE_FLOAT;

	return TYPE_IMPOSSIBLE;
}

void printChar(std::string const &value)
{
	char c = value[0];

	std::cout << "char: " << "'" << c << "'" << std::endl
			  << "int: " << static_cast<int>(c) << std::endl
			  << "float: " << static_cast<float>(c) << ".0f" << std::endl
			  << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printInt(std::string const &value)
{
	double val = std::strtod(value.c_str(), NULL);
	bool flag = false;

	if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
		flag = true;
	std::string c;
	if (flag == true || val < 0 || val > 127)
		c = "impossible";
	else if (val < 32 || val == 127)
		c = "Non displayable";
	else
	{
		c = "'";
		c += static_cast<char>(val);
		c += "'";
	}
	std::cout << "char: " << c << std::endl;
	if (flag == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	if (val < 1000000.0 && val > -1000000.0)
	{
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl
				  << "double: " << val << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl
				  << "double: " << val << std::endl;
	}
}

void printDouble(std::string const &value)
{
	if (value == "nan" || value == "+inf" || value == "-inf")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: " << value + 'f' << std::endl
				  << "double: " << value << std::endl;
	}
	else
	{
		double dbl = std::strtod(value.c_str(), NULL);
		int i = 0;
		bool flag = false;
		if (dbl > std::numeric_limits<int>::max() || dbl < std::numeric_limits<int>::min())
			flag = true;
		else
			i = static_cast<int>(dbl);
		std::string c;
		if (flag == true || dbl < 0 || dbl > 127)
			c = "impossible";
		else if (i < 32 || i == 127)
			c = "Non displayable";
		else
		{
			c = "'";
			c += static_cast<char>(i);
			c += "'";
		}

		std::cout << "char: " << c << std::endl;
		if (flag == true)
			std::cout << "int: " << "impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (flag == false && dbl == static_cast<double>(i) && dbl < 1000000.0 && dbl > -1000000.0)
		{
			std::cout << "float: " << static_cast<float>(dbl) << ".0f" << std::endl
					  << "double: " << dbl << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << static_cast<float>(dbl) << "f" << std::endl
					  << "double: " << dbl << std::endl;
		}
	}
}

void printFloat(std::string const &value)
{
	if (value == "nanf" || value == "+inff" || value == "-inff")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: " << value << std::endl
				  << "double: " << value.substr(0, value.length() - 1) << std::endl;
	}
	else
	{
		float flt = static_cast<float>(std::strtod(value.c_str(), NULL));
		int i = 0;
		bool flag = false;
		if (flt > std::numeric_limits<int>::max() || flt < std::numeric_limits<int>::min())
			flag = true;
		else
			i = static_cast<int>(flt);
		std::string c;
		if (flag == true || flt < 0 || flt > 127)
			c = "impossible";
		else if (i < 32 || i == 127)
			c = "Non displayable";
		else
		{
			c = "'";
			c += static_cast<char>(i);
			c += "'";
		}

		std::cout << "char: " << c << std::endl;
		if (flag == true)
			std::cout << "int: " << "impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (flag == false && flt == static_cast<double>(i) && flt < 1000000.0 && flt > -1000000.0)
		{
			std::cout << "float: " << flt << ".0f" << std::endl
					  << "double: " << static_cast<double>(flt) << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << flt << 'f' << std::endl
					  << "double: " << static_cast<double>(flt) << std::endl;
		}
	}
}

void ScalarConverter::convert(std::string const &value)
{
	e_type type;

	type = getType(value);
	switch (type)
	{
	case TYPE_IMPOSSIBLE:
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: impossible" << std::endl
				  << "double: impossible" << std::endl;
		break;
	}
	case TYPE_CHAR:
	{
		printChar(value);
		break;
	}
	case TYPE_INT:
	{
		printInt(value);
		break;
	}
	case TYPE_DOUBLE:
	{
		printDouble(value);
		break;
	}
	case TYPE_FLOAT:
	{
		printFloat(value);
		break;
	}
	}
}