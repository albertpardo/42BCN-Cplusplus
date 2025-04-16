/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:47:42 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/19 13:31:05 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <limits>
#include "PmergeMe.hpp"

bool	isPositiveInt(const char *str)
{
	char	*endptr;
	long	num;

	num = std::strtol(str, &endptr, 10);
	if (str != endptr && *endptr == '\0' && num <= std::numeric_limits<int>::max() && num > 0)
		return (true);
	return(false);
}

/*
 * mergeInsertSort Vector
 *
 * 1- Create Pairs ( for odd size the last value is associated to -1)
 * 2- Sort each pair values as (low,hight) pair (don´t look another pair)
 * 3- Sort all pair in ascendent order by low value of each pair.
 * 4- Push first number of the pair to sorted vector
 * 5- Push second number of pairs in the right place of sorted vector using 
 * 		'Binary Search Insertion'
 */

std::vector<int>	mergeInsertSortVector(std::vector<int> unsortVec)
{
	std::vector<int>								sortedVec;
	std::vector< std::pair<int, int> >				pairsVec;
	std::vector<int>::iterator						it;
	std::vector< std::pair<int, int> >::iterator	itp;
		
	if (isContainerSorted(unsortVec))
	{
		sortedVec = unsortVec;
		return (sortedVec);
	}

	//1- Create pairsVec
	it = unsortVec.begin();
	while(it !=unsortVec.end())
	{
		if (it < unsortVec.end() - 1)
		{
			pairsVec.push_back(std::make_pair(*it, *(it + 1)));
			it++;
		}
		else
			pairsVec.push_back(std::make_pair(-1, *it));
		it++;
	}
/*
	std::cout << "****Unsorted PairsVector" << std::endl;
	printPairContainer(pairsVec);
*/
	//2- Sort each pair as (low, hight)
	itp = pairsVec.begin();
	while(itp !=pairsVec.end())
	{
		if ((*itp).first > (*itp).second)
			std::swap((*itp).first, (*itp).second);
		itp++;
	}
/*
	std::cout << "****sorted Pairs" << std::endl;
	printPairContainer(pairsVec);
*/
	//3- Sort pairsVec by first number
	insertionSortPairs(pairsVec);
/*
	std::cout << "****sorted PairsVector" << std::endl;
	printPairContainer(pairsVec);
*/
	//4- Push first number of the pair to sorted vector
	itp = pairsVec.begin();
	while(itp !=pairsVec.end())
	{
		if ((*itp).first > 0)
			sortedVec.push_back((*itp).first);
		itp++;
	}

	//5- Push second number of pairs in the right place of sorted vector using Binary Search Insertion
	itp = pairsVec.begin();
	while(itp !=pairsVec.end())
	{
		binarySearchInsertion(sortedVec, (*itp).second); 
		itp++;
	}

	return (sortedVec);
}

/*
 * mergeInsertSortDeque
 *
 * 1- Create Pairs ( for odd size the last value is associated to -1)
 * 2- Sort each pair values as (low,hight) pair (don´t look another pair)
 * 3- Sort all pair in ascendent order by low value of each pair.
 * 4- Push first number of the pair to sorted deque
 * 5- Push second number of pairs in the right place of sorted deque using 
 */

std::deque<int>	mergeInsertSortDeque(std::deque<int> unsortDeque)
{
	std::deque<int>								sortedDeque;
	std::deque< std::pair<int, int> >			pairsDeque;
	std::deque<int>::iterator					it;
	std::deque< std::pair<int, int> >::iterator	itp;
		
	if (isContainerSorted(unsortDeque))
	{
		sortedDeque = unsortDeque;
		return (sortedDeque);
	}

	//1- Create pairsDeque
	it = unsortDeque.begin();
	while(it !=unsortDeque.end())
	{
		if (it < unsortDeque.end() - 1)
		{
			pairsDeque.push_back(std::make_pair(*it, *(it + 1)));
			it++;
		}
		else
			pairsDeque.push_back(std::make_pair(-1, *it));
		it++;
	}

	//2- Sort each pair as (low, hight)
	itp = pairsDeque.begin();
	while(itp !=pairsDeque.end())
	{
		if ((*itp).first > (*itp).second)
			std::swap((*itp).first, (*itp).second);
		itp++;
	}

	//3- Sort pairsDeque set by first number
	insertionSortPairs(pairsDeque);

	//4- Push first number of the pair to sorted deque
	itp = pairsDeque.begin();
	while(itp !=pairsDeque.end())
	{
		if ((*itp).first > 0)
			sortedDeque.push_back((*itp).first);
		itp++;
	}

	//5-  Push second number of pairs in the right place of sorted deque using Binary Search Insertion
	itp = pairsDeque.begin();
	while(itp !=pairsDeque.end())
	{
		binarySearchInsertion(sortedDeque, (*itp).second); 
		itp++;
	}

	return (sortedDeque);
}
