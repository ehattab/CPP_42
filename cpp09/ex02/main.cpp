/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:36:32 by ehattab           #+#    #+#             */
/*   Updated: 2026/11/14 19:00:14 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe p;

	if (p.parse(argc, argv) == 0)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	p.run(argc, argv);
	return 0;
}