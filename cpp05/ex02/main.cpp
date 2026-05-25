/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:14:48 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/25 20:18:46 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat god("nobody", 0);
		std::cout << god << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat trash("Poubelle", 151);
		std::cout << trash << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat bob("Bob", 137);
		Bureaucrat noob("Noob", 150);
		ShrubberyCreationForm shrub("Maison");

		std::cout << shrub << std::endl;

		noob.signForm(shrub);

		bob.signForm(shrub);

		noob.executeForm(shrub);

		bob.executeForm(shrub);
	}
	catch (std::exception &e)
	{

		std::cerr << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat jack("Jack", 45);
		RobotomyRequestForm robot("Claptrap");

		jack.signForm(robot);
		jack.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Lacrim");
		boss.executeForm(pardon);
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	return 0;
}