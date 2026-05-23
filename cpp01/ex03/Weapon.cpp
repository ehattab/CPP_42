/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:28:41 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/02 18:13:31 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type): type(_type)
{
}

const std::string& Weapon::getType(void) const
{
	return type;
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}

Weapon::~Weapon()
{
}