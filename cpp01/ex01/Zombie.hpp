/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:49:34 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/01 17:05:42 by ehattab          ###   ########.fr       */
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
	Zombie();
	~Zombie();
	void	announce(void);
	void	setName(std::string name);
};
Zombie*	zombieHorde( int N, std::string name );

#endif