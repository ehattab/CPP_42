/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:09:14 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/12 16:47:55 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* _Brain;
public:
	Cat();
	~Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	void	makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif