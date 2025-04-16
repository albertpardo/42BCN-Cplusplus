/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:47:00 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/22 17:55:25 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstdlib>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

#define ERR_OUT_RANGE "ERROR: No Positive integer value."
#define ERR_DUPLICATE "ERROR: Duplicated integer."

// TODO  START DELETE   
/*
 * TODO : Delete antes de entregar
 * Put on screen each pair from PairContainer
 */

template <typename T>
void	printPairContainer( T & container)
{
	typename T::iterator	it;

	it = container.begin();
	while (it != container.end())
	{
		std::cout << "(" << (*it).first << "," << (*it).second << ")";
		it++;
		if (it != container.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}
// TODO  END DELETE   

bool				isPositiveInt(const char *str);
std::vector<int>	mergeInsertSortVector(std::vector<int> & unsortVec);
std::deque<int>		mergeInsertSortDeque(std::deque<int> & unsortDeque);

/* ====  Templates === */

/*
 * Put a Positive string integer in Container T as int value
 * Throw a signal error for any issue 
 */

template <typename T>
T	strIntToContainer(char **argv)
{
	unsigned int	i;
	int				num;
	T				container;

	i = 1;
	while(argv[i])
	{
		if (isPositiveInt(argv[i]))
		{
			num = std::atoi(argv[i]);
			for ( typename T::iterator it = container.begin(); \
					it != container.end(); it++)
			{
				if (num == *it)
					throw std::runtime_error(ERR_DUPLICATE);
			}
			container.push_back(num);
		}
		else
			throw std::runtime_error(ERR_OUT_RANGE);
		i++;
	}
	return (container);
}

/*
 *  Checks if all values of container T are sort.
 *  - 'it' iterator for container
 *  - 'tmp'  container value to compare with next container value
 */

template <typename T>
bool	isContainerSorted( const T & container)
{
	typename T::const_iterator	it;
	typename T::value_type	tmp;

	it = container.begin();
	tmp = *it;
	it++;
	while(it !=container.end())
	{
		if (tmp > *it)
			return (false);
		tmp = *it;
		it++;
	}
	return (true);
}

/*
 * Each value of container is put on screen with a space between values
 */

template <typename T>
void	printContainer( T & container)
{
	typename T::iterator	it;
	
	it = container.begin();
	while (it != container.end())
	{
		std::cout << *it;
		it++;
		if (it != container.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

/*
 * "Insertion sort"
 * https://en.wikipedia.org/wiki/Insertion_sort
 */
/*
template <typename T>
void	insertionSortPairs(T & pairs)
{
	typename T::iterator it;
	typename T::iterator jt;

	if (pairs.size() == 0)
		return ;
	it = pairs.begin() + 1;
	while( it != pairs.end())
	{
		jt = it;
		while(jt > pairs.begin() && (*(jt-1)).first > (*jt).first)
		{
			std::swap(*jt, *(jt-1));
			jt--;
		}
		it++;
	}
}
*/

#endif
