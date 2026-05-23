/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:49:25 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/01 17:38:06 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "Zombie.hpp"


int	main(void)
{
	int n = 8;
	Zombie *horde = zombieHorde(n, "khemj");
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete[] (horde);
	return(0);
}