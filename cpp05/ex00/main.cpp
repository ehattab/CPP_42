/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:14:48 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/23 20:14:54 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat hehe("Hehe", 75);
		std::cout << hehe << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bad("Bad", 0);
		std::cout << bad << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bad("Bad", 151);
		std::cout << bad << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bob("Bob", 5);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "Apres increment : " << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat carol("Iheb", 5);
		std::cout << carol << std::endl;
		carol.decrementGrade();
		std::cout << "Apres decrement : " << carol << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat dave("Elyes", 1);
		std::cout << dave << std::endl;
		dave.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat neuille("Neuille", 150);
		std::cout << neuille << std::endl;
		neuille.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Original : " << original << std::endl;
		std::cout << "Copie    : " << copy << std::endl;
		copy.incrementGrade();
		std::cout << "Apres increment de la copie :" << std::endl;
		std::cout << "Original : " << original << std::endl;
		std::cout << "Copie    : " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}