/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:27:38 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/25 21:08:49 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeShrubbery(std::string const &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string const &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(std::string const &target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{

	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};
	AForm *(Intern::*makers[3])(std::string const &) const = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*makers[i])(target);
		}
	}

	std::cerr << "Intern couldn't create form: '" << formName << "' is unknown." << std::endl;
	return NULL;
}
