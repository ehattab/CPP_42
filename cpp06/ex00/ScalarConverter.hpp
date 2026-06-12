/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:19:25 by ehattab           #+#    #+#             */
/*   Updated: 2026/06/12 19:06:01 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

enum e_type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_IMPOSSIBLE
};

class ScalarConverter
{
private:
	ScalarConverter();

public:
	~ScalarConverter();
	static std::string convert(std::string value);
};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

#endif