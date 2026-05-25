/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:14:48 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/25 21:10:17 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *rrf;
	AForm *nope;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	nope = someRandomIntern.makeForm("rien", "Personne");

	std::cout << *rrf << std::endl;
	if (rrf)
	{
		delete rrf;
	}
	if (nope)
	{
		delete nope;
	}
}