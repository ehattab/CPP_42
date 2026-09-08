/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:19:51 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/08 20:28:28 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Span.hpp"

int main( void )
{
	Span sp(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(100);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span empty(5);
	try
	{
		empty.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> big;
	for (int i = 0; i < 10000; i++)
		big.push_back(i);
 
	Span Big(10000);
	Big.addNumber(big.begin(), big.end());
	std::cout << Big.shortestSpan() << std::endl;
	std::cout << Big.longestSpan() << std::endl;
 
	return 0;
}