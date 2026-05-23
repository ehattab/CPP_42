/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:07:43 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/01 16:42:22 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string _name;
	public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
};
Zombie*	newZombie( std::string name );
void randomChump( std::string name );

#endif