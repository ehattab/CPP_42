/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 19:37:11 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/08 20:21:11 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void Span::addNumber(int n)
{
	if (_Span.size() < _n && _n > 0)
		_Span.push_back(n);
	else
		throw OutException();
}

int Span::longestSpan()
{
	if (_Span.size() <= 1)
		throw OutException();
	std::vector<int>::iterator minIT = std::min_element(_Span.begin(), _Span.end());
	std::vector<int>::iterator maxIT = std::max_element(_Span.begin(), _Span.end());

	return (*maxIT - *minIT);
}

int Span::shortestSpan()
{
	if (_Span.size() <= 1)
		throw OutException();
	std::vector<int> sorted = _Span;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator a = sorted.begin();
	std::vector<int>::iterator b = sorted.begin() + 1;

	int x = 0;
	for (unsigned int i = 0; i < sorted.size() - 1; i++)
	{
		if (i == 0)
			x = *b - *a;
		if (*b - *a < x)
			x = *b - *a;
		a++;
		b++;
	}
	return (x);
}