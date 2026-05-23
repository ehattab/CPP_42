/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:44:51 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/21 20:27:50 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	totalContacts = 0;
}

void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	std::cout << "First name: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty() && !isWhiteSpace(input))
			break;
		std::cout << "Field cannot be empty. Try again: ";
	}
	newContact.setFirstName(input);

	std::cout << "Last name: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty() && !isWhiteSpace(input))
			break;
		std::cout << "Field cannot be empty. Try again: ";
	}
	newContact.setLastName(input);

	std::cout << "Nickname: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty() && !isWhiteSpace(input))
			break;
		std::cout << "Field cannot be empty. Try again: ";
	}
	newContact.setNickname(input);

	std::cout << "Phone number: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty() && isDigits(input))
			break;
		std::cout << "Phone number must contain digits only. Try again: ";
	}
	newContact.setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty() && !isWhiteSpace(input))
			break;
		std::cout << "Field cannot be empty. Try again: ";
	}
	newContact.setDarkestSecret(input);
	contacts[index] = newContact;
	index = (index + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
	std::cout << "Contact added successfully.\n";
}

void PhoneBook::searchContact()
{
	if (totalContacts == 0)
	{
		std::cout << "PhoneBook is empty\n";
		return;
	}

	for (int i = 0; i < totalContacts; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getNickname()) << "\n";
	}

	std::cout << "Index: ";
	std::string input;
	if (!std::getline(std::cin, input))
		return;

	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid index\n";
		return;
	}
	int i = input[0] - '0';

	if (i < 0 || i >= totalContacts)
	{
		std::cout << "Invalid index\n";
		return;
	}

	std::cout << "First name: " << contacts[i].getFirstName() << "\n";
	std::cout << "Last name: " << contacts[i].getLastName() << "\n";
	std::cout << "Nickname: " << contacts[i].getNickname() << "\n";
	std::cout << "Phone number: " << contacts[i].getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << "\n";
}
