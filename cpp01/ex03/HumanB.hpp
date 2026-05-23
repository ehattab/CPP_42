/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:50:06 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/02 16:51:35 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
	std::string	name;
	Weapon* weapon;
	public:
	HumanB(std::string name);
	~HumanB();
	void	attack(void) const;
	void	setWeapon(Weapon &wp);
};


#endif