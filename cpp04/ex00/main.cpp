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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n------CORRECT ANIMAL TESTS (WITH VIRTUAL)------" << std::endl;
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "\n----GET TYPE-----" << std::endl;
	std::cout << "dog is a: " << dog->getType() << std::endl;
	std::cout << "cat is a: " << cat->getType() << std::endl;

	std::cout << "\n-----MAKE SOUND-----" << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout << "\n\n-------WRONG ANIMAL TESTS (WITHOUT VIRTUAL)-------" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	const WrongCat *trueWrongCat = new WrongCat();

	std::cout << "\n------GET TYPE (WRONG)-----" << std::endl;
	std::cout << "wrongCat is a: " << wrongCat->getType() << std::endl;

	std::cout << "\n------MAKE SOUND (WRONG)----" << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "But if the pointer is exactly a WrongCat: ";
	trueWrongCat->makeSound();

	std::cout << "\n\n---------DESTRUCTORS---------" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete wrongMeta;
	delete wrongCat;
	delete trueWrongCat;

	return 0;
}