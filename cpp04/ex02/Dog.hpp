/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:35:06 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/12 16:59:47 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _Brain;
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &other);
	void	makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif