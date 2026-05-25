/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:12:40 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/25 19:36:36 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45, 0), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &f)
{
	os << "RobotomyRequestForm: " << f.getName()
	<< " | Signed: " << (f.getIsSigned() ? "yes" : "no")
	<< " | Grade to sign: " << f.getGradeToSign()
	<< " | Grade to execute: " << f.getGradeToExecute();
	return os;
}

void RobotomyRequestForm::executeAction() const
{
	srand(time(NULL));
	std::cout << "Bzz Crap ZIOONNNN ";
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomiz of " << _target << " failed" << std::endl;
}