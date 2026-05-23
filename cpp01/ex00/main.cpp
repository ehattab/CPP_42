/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:07:22 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/01 16:40:37 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Zombie.hpp"


int	main(void)
{
	Zombie *z;
	z = newZombie("Fank");
	z->announce();
	delete (z);
	randomChump("Zoo");
	return(0);
}