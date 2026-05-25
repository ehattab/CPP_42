/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 20:27:42 by ehattab           #+#    #+#             */
/*   Updated: 2026/05/25 21:00:41 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();

AForm *makeForm(std::string const &formName, std::string const &target) const;
private:
	AForm *makeShrubbery(std::string const &target) const;
	AForm *makeRobotomy(std::string const &target) const;
	AForm *makePresidential(std::string const &target) const;
};

#endif