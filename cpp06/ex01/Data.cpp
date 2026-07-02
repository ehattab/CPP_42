/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:28:10 by ehattab           #+#    #+#             */
/*   Updated: 2026/07/02 18:56:05 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	value = "default";
}

Data::Data(Data const &other): value(other.value)
{
}

Data &Data::operator=(Data const &other)
{
	value = other.value;
	return *this;
}

Data::Data(std::string str): value(str)
{
}

Data::~Data()
{
}