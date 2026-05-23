/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:17:38 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/02 17:18:14 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
	std::string	type;
	
	public:
	const std::string& getType(void) const;
	void setType(std::string newType);
	Weapon(std::string _type);
	~Weapon();
};

#endif