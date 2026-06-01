/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:19:25 by ehattab           #+#    #+#             */
/*   Updated: 2026/06/01 21:02:04 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

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