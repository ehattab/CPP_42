/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:42:57 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/21 20:25:18 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>

#include "contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;
	int totalContacts;
	std::string formatField(std::string str) const;
	bool isWhiteSpace(const std::string &str) const;
	bool isDigits(const std::string &str) const;

public:
	PhoneBook();

	void addContact();
	void searchContact();
};

#endif