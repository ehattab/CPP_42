/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:39:28 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/25 20:02:58 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137, 0), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &f)
{
	os << "ShrubberyCreationForm: " << f.getName()
	   << " | Signed: " << (f.getIsSigned() ? "yes" : "no")
	   << " | Grade to sign: " << f.getGradeToSign()
	   << " | Grade to execute: " << f.getGradeToExecute();
	return os;
}

void ShrubberyCreationForm::executeAction() const
{
	std::string file = _target + "_shrubbery";
	std::ofstream of(file.c_str());
	if (!of.is_open())
	{
		std::cerr << "Erreur : Impossible d'ouvrir ou de créer le fichier !" << std::endl;
		throw;
	}
	of << "               ,@@@@@@@,                  \n"
	   << "       ,,,.   ,@@@@@@/@@,  .oo8888o.      \n"
	   << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o     \n"
	   << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'    \n"
	   << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    \n"
	   << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     \n"
	   << "  `&%\\ ` /%&'    |.|       \\ '|8'       \n"
	   << "       |o|        | |         | |         \n"
	   << "       |.|        | |         | |         \n"
	   << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ \n"
	   << std::endl;
}