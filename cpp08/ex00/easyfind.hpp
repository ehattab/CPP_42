/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:29:40 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/05 18:05:36 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <algorithm>

class OutException : public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Out of range or missing");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int y)
{
	typename T::iterator it = std::find(container.begin(),container.end(), y);

	if (it == container.end())
		throw OutException();

	return (it);
}


#endif