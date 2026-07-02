/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:25:09 by ehattab           #+#    #+#             */
/*   Updated: 2026/07/02 20:18:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data("elyes");
	Data* original_ptr = &data;
	uintptr_t raw;
	std::cout << "Data value = " << original_ptr->value << std::endl;
	std::cout << "Data ptr = " << original_ptr << std::endl;
	raw = Serializer::serialize(original_ptr);
	std::cout << "Data serialize = " << raw << std::endl;
	Data* copy = Serializer::deserialize(raw);
	std::cout << "Copy ptr = " << copy << std::endl;
	std::cout << "Copy value = " << copy->value << std::endl;
}