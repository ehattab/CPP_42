/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:19:10 by ehattab           #+#    #+#             */
/*   Updated: 2026/03/03 20:34:08 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Harl.hpp"

int main(void)
{
	Harl donut;

	std::cout << "--- DEBUG ---" << std::endl;
	donut.complain("DEBUG");
	std::cout << "--- INFO ---" << std::endl;
	donut.complain("INFO");
	std::cout << "--- WARNING ---" << std::endl;
	donut.complain("WARNING");
	std::cout << "--- ERROR ---" << std::endl;
	donut.complain("ERROR");
	return (0);
}