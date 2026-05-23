/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:57:11 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/10 17:40:22 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n-------CONSTRUCTORS------" << std::endl;
	ScavTrap unknown;
	ScavTrap scav("Serena");
	ScavTrap clone(scav);

	std::cout << "\n-------ASSIGNMENT-------" << std::endl;
	unknown = scav;

	std::cout << "\n-------ATTACK-------" << std::endl;
	scav.attack("Target1");

	std::cout << "\n------DAMAGE------" << std::endl;
	scav.takeDamage(30);

	std::cout << "\n------REPAIR------" << std::endl;
	scav.beRepaired(20);

	std::cout << "\n------SPECIAL------" << std::endl;
	scav.guardGate();

	std::cout << "\n------ENERGY-------" << std::endl;
	ScavTrap runner("Runner");

	for (int i = 0; i < 51; i++)
	{
		runner.attack("Dummy");
	}
	runner.beRepaired(10);

	std::cout << "\n------DEATH-----" << std::endl;
	ScavTrap poorGuy("Kenny");
	poorGuy.takeDamage(150);
	poorGuy.attack("Zombie");
	poorGuy.beRepaired(50);

	std::cout << "\n------DESTRUCTORS-----" << std::endl;
	return 0;
}