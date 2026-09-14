/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:26:19 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/05 18:05:20 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
#define Array_HPP
#include <exception>

template <typename T>
class Array
{
	private :
	size_t _n;
	T *_array;
	public :
	Array() : _n(0), _array(NULL) {}
	Array(unsigned int n) : _n(n), _array(new T[n]) {}
	Array(Array const &src) : _n(src._n)
	{
		_array = new T[src._n];
		for (size_t i = 0; i < src._n; i++)
			_array[i] = src._array[i];
	}
	Array &operator=(Array const &src)
	{
		if (this != &src)
		{
			delete[] _array;
			_n = src._n;
			_array = new T[src._n];
			for (size_t i = 0; i < src._n; i++)
				_array[i] = src._array[i];
		}
		return (*this);
	}
	T &operator[](unsigned int index)
	{
		if (index >= _n)
			throw OutException();
		return (_array[index]);
	}
	T const &operator[](unsigned int index) const
	{
		if (index >= _n)
			throw OutException();
		return (_array[index]);
	}
	class OutException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Out of range or missing");
		}
	};
	~Array() { delete[] _array; }
	size_t size(void) const
	{ return _n; }

};

#endif