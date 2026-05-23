/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:54:32 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/10 17:45:01 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\n-------CONSTRUCTORS------" << std::endl;
	FragTrap unknown;
	FragTrap frag("Gaston");
	FragTrap clone(frag);

	std::cout << "\n-------ASSIGNMENT-------" << std::endl;
	unknown = frag;

	std::cout << "\n-------ATTACK-------" << std::endl;
	frag.attack("Target1");

	std::cout << "\n------DAMAGE------" << std::endl;
	frag.takeDamage(30);

	std::cout << "\n------REPAIR------" << std::endl;
	frag.beRepaired(20);

	std::cout << "\n------SPECIAL------" << std::endl;
	frag.highFivesGuys();

	std::cout << "\n------ENERGY-------" << std::endl;
	FragTrap runner("Runner");
	for (int i = 0; i < 101; i++)
	{
		runner.attack("Dummy");
	}
	runner.beRepaired(10);

	std::cout << "\n------DEATH-----" << std::endl;
	FragTrap poorGuy("Kenny");
	poorGuy.takeDamage(150);
	poorGuy.attack("Zombie");
	poorGuy.beRepaired(50);

	std::cout << "\n------DESTRUCTORS-----" << std::endl;
	return 0;
}