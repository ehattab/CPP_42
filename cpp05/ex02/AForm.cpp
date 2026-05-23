/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:16:40 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/23 20:57:37 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high (min is 1)";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low (max is 150)";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &other)
	: _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{}

std::string const &AForm::getName() const
{
	return _name;
}
bool AForm::getIsSigned() const
{
	return _isSigned;
}
int AForm::getGradeToSign() const
{
	return _gradeToSign;
}
int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	os << "AForm: " << f.getName()
	<< " | Signed: " << (f.getIsSigned() ? "yes" : "no")
	<< " | Grade to sign: " << f.getGradeToSign()
	<< " | Grade to execute: " << f.getGradeToExecute();
	return os;
}