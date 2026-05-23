/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:58:17 by ehattab           #+#    #+#             */
/*   Updated: 2026/02/21 20:04:38 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setFirstName(std::string value)
{
	firstName = value;
}

void Contact::setLastName(std::string value)
{
	lastName = value;
}

void Contact::setNickname(std::string value)
{
	nickname = value;
}

void Contact::setPhoneNumber(std::string value)
{
	phoneNumber = value;
}

void Contact::setDarkestSecret(std::string value)
{
	darkestSecret = value;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}