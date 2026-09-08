/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 19:33:07 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/08 20:29:09 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Span_HPP
#define Span_HPP
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	private :
	unsigned int _n;
	std::vector<int> _Span;
	public :
	Span() : _n(0) {}
	Span(unsigned int n) : _n(n) {}
	Span(Span const &src) : _n(src._n), _Span(src._Span) {}
	Span &operator=(Span const &src)
	{
		if (this != &src)
		{
			_n = src._n;
			_Span = src._Span;
		}
		return (*this);
	}
	int &operator[](unsigned int index)
	{
		if (index >= _n)
			throw OutException();
		return (_Span[index]);
	}
	int const &operator[](unsigned int index) const
	{
		if (index >= _n)
			throw OutException();
		return (_Span[index]);
	}
	class OutException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Out of range or missing number");
		}
	};
	~Span(){}
	void addNumber(int n);
	template <typename It>
	void addNumber(It begin, It end)
	{
		size_t distance = std::distance(begin, end);
		if (distance >  (_n - _Span.size()))
			throw OutException();
		_Span.insert(_Span.end(), begin, end);
	}
	int longestSpan();
	int shortestSpan();
};

#endif