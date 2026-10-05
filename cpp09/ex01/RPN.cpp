/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:37:17 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/20 20:11:21 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void calculateRPN(std::string const &expr)
{
	std::stringstream ss(expr);
	std::string token;
	std::stack<int> pile;

	while (ss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (pile.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}

			int b = pile.top();
			pile.pop();
			int a = pile.top();
			pile.pop();

			if (token == "+")
				pile.push(a + b);
			else if (token == "-")
				pile.push(a - b);
			else if (token == "*")
				pile.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error" << std::endl;
					return;
				}
				pile.push(a / b);
			}
		}
		else
		{
			if (token.length() != 1 || !isdigit(token[0]))
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			pile.push(token[0] - '0');
		}
	}
	if (pile.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << pile.top() << std::endl;
}