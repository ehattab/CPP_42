/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:19:44 by ehattab           #+#    #+#             */
/*   Updated: 2026/06/12 19:10:03 by ehattab          ###   ########.fr       */
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

static e_type getType(std::string value)
{
	if (value == "nan" || value == "+inf" || value == "-inf")
		return TYPE_DOUBLE;
	else if (value == "nanf" || value == "+inff" || value == "-inff")
		return TYPE_FLOAT;
	else if (value.size() == 1 && value[0] >= 10 && value[0] <= 127
			&& value[0] < '0' || value[0] > '9')
		return TYPE_CHAR;

	bool flag = false;
	int sign = 0;
	int point = 0;
	int i = 0;

	if (value[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (value[0] == '+')
	{
		sign = 1;
		i++;
	}
	for(i; value[i]; i++)
	{
		if (value[i] >= 10 && value[i] <= 127
			&& value[i] < '0' && value[i] > '9' && value[i] != '.'
			&& value[value.size() - 1] < '0' || value[value.size() - 1] > '9' && value[value.size()] != 'f')
			flag = true;
		if (value[i] == '.')
			point++;
		if (point > 1)
			flag = true;
		if (flag == true)
			return TYPE_IMPOSSIBLE;
	}
	if (point == 1 && value[value.size() - 1] == 'f')
		return TYPE_FLOAT;
	if (value[value.size() - 1] >= '0' && value[value.size() - 1] <= '9' && point == 0)
		TYPE_INT;
	if (point == 1 && value[value.size() - 1] >= '0' && value[value.size() - 1] <= '9')
	return TYPE_DOUBLE;
}
