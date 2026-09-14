/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:19:51 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/09 22:10:59 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(42);
	mstack.push(24);

	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;

	mstack.pop();

	std::cout << mstack.top() << std::endl;

	mstack.push(10);
	mstack.push(20);
	mstack.push(30);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}