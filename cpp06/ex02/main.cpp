/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:51:07 by ehattab           #+#    #+#             */
/*   Updated: 2026/07/02 21:51:28 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
	{
		std::cout << "A" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "C" << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Type ptr is A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Type ptr is  B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Type ptr is C" << std::endl;
	else
		std::cout << "Broken" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type ref is A" << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type ref is B" << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type ref is C" << std::endl;
	}
	catch (std::exception &e)
	{}
}

int main(void)
{
	std::srand(std::time(NULL));

	Base *p = generate();
	identify(p);
	identify(*p);

	delete (p);
}