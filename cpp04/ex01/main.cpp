/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:21:02 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/12 16:47:55 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "\n--------------ANIMALS TEST------------" << std::endl;
	int arraySize = 10;
	Animal *animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < arraySize; i++)
	{
		animals[i]->makeSound();
	}

	for (int i = 0; i < arraySize; i++)
	{
		delete animals[i];
	}

	std::cout << "\n-------------DEEP COPY TEST----------" << std::endl;
	Dog *dogA = new Dog();
	dogA->getBrain()->setIdeas("ABC");
	std::cout << "dogA idea is: " << dogA->getBrain()->getIdeas()[0] << std::endl;
	Dog *dogB = new Dog(*dogA);
	delete dogA;
	std::cout << "dogB idea is: " << dogB->getBrain()->getIdeas()[0] << std::endl;
	delete dogB;

	std::cout << "\n-------------SUBJECT TEST----------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	
	return 0;
}