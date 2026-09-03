/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:26:05 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/03 20:49:47 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Array.hpp"

template <typename T>
void print_tab(T array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << std::endl;
	}
}

void test_const(Array<int> const &tab)
{
	std::cout << tab[0] << std::endl;
}

int main( void )
{
	Array<int> tab(4);
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;

	Array<int> array(tab);
	array[0] = 0;
	print_tab(tab);
	print_tab(array);
	test_const(array);
	try
	{
		std::cout << array[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Array<std::string> ARRAY(1);
	ARRAY[0] = "Hello world!";
	print_tab(ARRAY);
	return 0;
}