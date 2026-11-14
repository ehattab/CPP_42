/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 18:37:17 by ehattab           #+#    #+#             */
/*   Updated: 2026/11/14 19:21:39 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	vec = other.vec;
	deq = other.deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

int PmergeMe::parse(int argc, char **argv)
{
	int i = 1;

	while (i < argc)
	{
		std::string arg = argv[i];
		if (arg.empty())
			return 0;
		long nb = 0;
		size_t j = 0;
		while (j < arg.size())
		{
			if (arg[j] < '0' || arg[j] > '9')
				return 0;
			nb = nb * 10 + (arg[j] - '0');
			if (nb > INT_MAX)
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

void PmergeMe::run(int argc, char **argv)
{
	std::cout << "Before:";
	int i = 1;
	while (i < argc)
	{
		std::cout << " " << std::atoi(argv[i]);
		i++;
	}
	std::cout << std::endl;
	clock_t start = clock();
	i = 1;
	while (i < argc)
	{
		vec.push_back(std::atoi(argv[i]));
		i++;
	}
	vec = sortVector(vec);
	clock_t end = clock();
	double timeVec = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
	start = clock();
	i = 1;
	while (i < argc)
	{
		deq.push_back(std::atoi(argv[i]));
		i++;
	}
	deq = sortDeque(deq);
	end = clock();
	double timeDeq = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After:";
	size_t k = 0;
	while (k < vec.size())
	{
		std::cout << " " << vec[k];
		k++;
	}
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque : " << timeDeq << " us" << std::endl;
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
	std::vector<size_t> order;
	size_t prevJ = 1;
	size_t curJ = 3;

	while (prevJ < n)
	{
		size_t k = curJ;
		if (k > n)
			k = n;
		while (k > prevJ)
		{
			order.push_back(k);
			k--;
		}
		size_t nextJ = curJ + 2 * prevJ;
		prevJ = curJ;
		curJ = nextJ;
	}
	return order;
}


std::vector<int> PmergeMe::sortVector(std::vector<int> v)
{
	if (v.size() <= 1)
		return v;
	std::vector<int> bigs;
	std::vector<int> smalls;
	size_t i = 0;
	while (i + 1 < v.size())
	{
		if (v[i] > v[i + 1])
		{
			bigs.push_back(v[i]);
			smalls.push_back(v[i + 1]);
		}
		else
		{
			bigs.push_back(v[i + 1]);
			smalls.push_back(v[i]);
		}
		i = i + 2;
	}
	bool hasStraggler = false;
	int straggler = 0;
	if (v.size() % 2 == 1)
	{
		hasStraggler = true;
		straggler = v[v.size() - 1];
	}
	std::vector<int> mainChain = sortVector(bigs);
	std::vector<int> SmallPend;
	std::vector<bool> used(bigs.size(), false);
	size_t k = 0;
	while (k < mainChain.size())
	{
		size_t j = 0;
		while (j < bigs.size())
		{
			if (used[j] == false && bigs[j] == mainChain[k])
			{
				SmallPend.push_back(smalls[j]);
				used[j] = true;
				break;
			}
			j++;
		}
		k++;
	}
	mainChain.insert(mainChain.begin(), SmallPend[0]);
	if (hasStraggler == true)
		SmallPend.push_back(straggler);
	std::vector<size_t> order = jacobsthalOrder(SmallPend.size());
	std::vector<size_t> posBig;
	k = 0;
	while (k < bigs.size())
	{
		posBig.push_back(k + 1);
		k++;
	}
	i = 0;
	while (i < order.size())
	{
		size_t index = order[i] - 1;
		int value = SmallPend[index];
		size_t left = 0;
		size_t right;
		if (index < posBig.size())
			right = posBig[index];
		else
			right = mainChain.size();
		while (left < right)
		{
			size_t mid = (left + right) / 2;
			if (mainChain[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		mainChain.insert(mainChain.begin() + left, value);
		k = 0;
		while (k < posBig.size())
		{
			if (posBig[k] >= left)
				posBig[k]++;
			k++;
		}
		i++;
	}
	return mainChain;
}

std::deque<size_t> PmergeMe::jacobsthalOrderDeque(size_t n)
{
	std::deque<size_t> order;
	size_t prevJ = 1;
	size_t curJ = 3;

	while (prevJ < n)
	{
		size_t k = curJ;
		if (k > n)
			k = n;
		while (k > prevJ)
		{
			order.push_back(k);
			k--;
		}
		size_t nextJ = curJ + 2 * prevJ;
		prevJ = curJ;
		curJ = nextJ;
	}
	return order;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> d)
{
	if (d.size() <= 1)
		return d;
	std::deque<int> bigs;
	std::deque<int> smalls;
	size_t i = 0;
	while (i + 1 < d.size())
	{
		if (d[i] > d[i + 1])
		{
			bigs.push_back(d[i]);
			smalls.push_back(d[i + 1]);
		}
		else
		{
			bigs.push_back(d[i + 1]);
			smalls.push_back(d[i]);
		}
		i = i + 2;
	}
	bool hasStraggler = false;
	int straggler = 0;
	if (d.size() % 2 == 1)
	{
		hasStraggler = true;
		straggler = d[d.size() - 1];
	}
	std::deque<int> mainChain = sortDeque(bigs);
	std::deque<int> SmallPend;
	std::deque<bool> used(bigs.size(), false);
	size_t k = 0;
	while (k < mainChain.size())
	{
		size_t j = 0;
		while (j < bigs.size())
		{
			if (used[j] == false && bigs[j] == mainChain[k])
			{
				SmallPend.push_back(smalls[j]);
				used[j] = true;
				break;
			}
			j++;
		}
		k++;
	}
	mainChain.insert(mainChain.begin(), SmallPend[0]);
	if (hasStraggler == true)
		SmallPend.push_back(straggler);
	std::deque<size_t> order = jacobsthalOrderDeque(SmallPend.size());
	std::deque<size_t> posBig;
	k = 0;
	while (k < bigs.size())
	{
		posBig.push_back(k + 1);
		k++;
	}
	i = 0;
	while (i < order.size())
	{
		size_t index = order[i] - 1;
		int value = SmallPend[index];
		size_t left = 0;
		size_t right;
		if (index < posBig.size())
			right = posBig[index];
		else
			right = mainChain.size();
		while (left < right)
		{
			size_t mid = (left + right) / 2;
			if (mainChain[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		mainChain.insert(mainChain.begin() + left, value);
		k = 0;
		while (k < posBig.size())
		{
			if (posBig[k] >= left)
				posBig[k]++;
			k++;
		}
		i++;
	}
	return mainChain;
}