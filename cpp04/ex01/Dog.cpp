/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:37:22 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/12 17:37:10 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_Brain = new Brain;
	std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::~Dog()
{
	delete (_Brain);
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	_Brain = new Brain();
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		*this->_Brain = *other._Brain;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "WAAAAAAAF!!!" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->_Brain);
}