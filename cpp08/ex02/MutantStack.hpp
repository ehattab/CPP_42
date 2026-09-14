/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:17:00 by ehattab           #+#    #+#             */
/*   Updated: 2026/09/09 20:32:39 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <algorithm>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const &src) : std::stack<T>(src) {}
	MutantStack &operator=(MutantStack const &src)
	{
		if (this != &src)
			std::stack<T>::operator=(src);
		return *this;
	}
	~MutantStack() {}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void) { return (this->c.begin()); }
	iterator end(void) { return (this->c.end()); }

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

#endif