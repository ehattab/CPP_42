/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:21:02 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/12 17:04:07 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	dog->makeSound();
	cat->makeSound();

	// const Animal* animal = new Animal();

	delete dog;
	delete cat;
	return 0;
}