/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:01:17 by ehattab           #+#    #+#             */
/*   Updated: 2026/07/02 18:19:50 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &other);
	Serializer &operator=(Serializer const &other);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif