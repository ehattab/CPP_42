/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:10:05 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/12 17:37:01 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	_Brain = new Brain;
	std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::~Cat()
{
	delete (_Brain);
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	_Brain = new Brain();
	*this = other;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		*this->_Brain = *other._Brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAAOUUUU!!!" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->_Brain);
}