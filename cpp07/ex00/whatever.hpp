/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:21:17 by ehattab           #+#    #+#             */
/*   Updated: 2026/08/24 18:10:39 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T const a, T const b)
{
	if (a == b)
		return b;
	if (a > b)
		return b;
	return a;
}

template <typename T>
T max(T const a, T const b)
{
	if (a == b)
		return b;
	if (a > b)
		return a;
	return b;
}

#endif