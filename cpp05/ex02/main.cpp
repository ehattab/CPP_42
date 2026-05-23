/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:14:48 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/23 20:41:53 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form contract("Contract", 50, 25);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form bad("Bad", 0, 25);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form bad("Bad", 50, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form contract("Contract", 50, 25);
		Bureaucrat elyes("Elyes", 42);
		std::cout << contract << std::endl;
		std::cout << elyes << std::endl;
		elyes.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form secret("Top Secret", 10, 5);
		Bureaucrat bob("Bob", 42);
		std::cout << secret << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(secret);
		std::cout << secret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form memo("Memo", 100, 50);
		Bureaucrat jeff("Jeff", 1);
		Bureaucrat bob("Bob", 1);
		jeff.signForm(memo);
		std::cout << memo << std::endl;
		bob.signForm(memo);
		std::cout << memo << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form form("Exact", 50, 25);
		Bureaucrat exact("Exact", 50);
		std::cout << form << std::endl;
		exact.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form form("Almost", 50, 25);
		Bureaucrat almost("Almost", 51);
		almost.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}