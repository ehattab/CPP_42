/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:37:17 by ehattab           #+#    #+#             */
/*   Updated: 2026/11/14 19:20:58 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <climits>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<int> vec;
	std::deque<int> deq;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	int parse(int argc, char **argv);
	void run(int argc, char **argv);

	std::vector<int> sortVector(std::vector<int> v);
	std::vector<size_t> jacobsthalOrder(size_t n);
	std::deque<int> sortDeque(std::deque<int> d);
	std::deque<size_t> jacobsthalOrderDeque(size_t n);
};

#endif