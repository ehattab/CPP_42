/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:26:05 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/05 18:03:36 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main( void )
{
	std::vector<int> container;
	for (int i = 0; i < 4; i++)
		container.push_back(i);
	std::vector<int>::iterator it;
	try
	{
		it = easyfind(container, 3);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		it = easyfind(container, 6);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::list<char> lc;
	lc.push_back('a');
	lc.push_back('b');
	lc.push_back('c');
	std::list<char>::iterator it2;
	try
	{
		it2 = easyfind(lc, 'b');
		std::cout << *it2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		it2 = easyfind(lc, 'z');
		std::cout << *it2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}