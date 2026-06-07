/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usr <usr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:19:44 by ehattab           #+#    #+#             */
/*   Updated: 2026/06/02 15:54:21 by usr              ###   ########.fr       */
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

static std::string convert(std::string value)
{
	for(int i = 0; value[i]; i++)
	{
		if (value[i] == '-' || value[i] == '+')
			i++;
		if (value[i] >= 10 && value[i] <= 127);
		if (value[i] == '.' || value[i] == 'f');
		
	}
}