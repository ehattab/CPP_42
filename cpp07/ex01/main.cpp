/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:26:05 by ehattab           #+#    #+#             */
/*   Updated: 2026/08/30 18:02:10 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "iter.hpp"

template <typename T>
void print_tab(T *array, size_t const val)
{
	for (size_t i = 0; i < val; i++)
		std::cout << array[i] << std::endl;
}

void incr(int &x)
{
	x = x + 1;
}

void toMaj(char &a)
{
	a = a - 32;
}

int main( void )
{
	int tab[4] = {0, 1, 2, 3};
	char array[4] = {'a', 'b', 'c', 'd'};

	print_tab(tab, 4);
	iter(tab, 4, incr);
	print_tab(tab, 4);
	print_tab(array, 4);
	iter(array, 4, toMaj);
	print_tab(array, 4);
	return 0;
}