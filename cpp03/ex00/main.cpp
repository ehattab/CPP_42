/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:14:29 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/08 15:48:59 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot("Rob");

	std::cout << "\n------Test1-------" << std::endl;
	robot.attack("Bob");
	robot.takeDamage(5);
	robot.beRepaired(3);

	std::cout << "\n-------Test2-------" << std::endl;
	robot.takeDamage(10);
	robot.attack("Bob");
	robot.beRepaired(5);

	std::cout << "\n--------Test3---------" << std::endl;
	ClapTrap robot2("Flash");
	for (int i = 0; i < 11; i++)
	{
		robot2.attack("a wall");
	}
	robot2.beRepaired(5);
	return 0;
}