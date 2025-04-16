/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:47:00 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/24 13:34:19 by apardo-m         ###   ########.fr       */
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

#define ODD_DEFAULT_VAL -1

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
int					jacobsthal(int n);
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

/*---- Start Merge sort ---*/

template <typename T>
static void merge(T & vec, int left, int mid, int right)
{
    int	i, j, k;

    // Create temporary vector to store order values
    T	tmp(right - left + 1);
    
	// Merge to tmp in sort way
    i = left;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
            tmp[k++] = vec[i++];
		else
            tmp[k++] = vec[j++];
    }

	// Copy the remaining elements in first half until 'mid' pos
	while (i <= mid)
		tmp[k++] = vec[i++];

    // Copy the remaining elements in second half  until 'right' pos
    while (j <= right)
		tmp[k++] = vec[j++];

	//Copy sorted values from 'tmp' to original container
	for (int z = 0; z < k; z++)
		vec[left + z] = tmp[z];
}

template <typename T>
static void mergeSort(T & vec, int left, int right)
{
    if (left < right)
   	{
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // Merge the sorted halves
        merge(vec, left, mid, right);
    }
}

/*---- End Merge Sort ---*/

/* -- Start -- Generate positions to use in 'Binary Insertion' -- */

/*
 * Generate a Jacobsthal sequence starting in 3 based on the size of Container
 * 3, 5 , 11 ,..... 
 *
 */

template <typename T>
static void generateSequenceJacob(T & jacobSequence, int size)
{
	int	jcobstalIndex;
	int index;

	index = 3;
	jcobstalIndex = jacobsthal(index);
	while (jcobstalIndex <= size)
	{
		jacobSequence.push_back(jcobstalIndex);
		jcobstalIndex = jacobsthal(++index);
	}
}

/*
 * Generate positions as FordJohnsonAlgorithm says for use in 'Binary Insertion' 
 * using Jacobsthal sequence.
 *
 * The values of Jacobsthal sequence must be compesated with '-1' to get the right
 *  position in the container.
 *
 * 1 - Generate positions using Jacobsthal sequence
 * 2- If last value of Jacobsthal sequence is minor than container' size 'positions'
 * container is fulled from last value of Jaco to size. 
 */

template <typename T>
static void generatePositions(T & positions, int size)
{
	T						jacobSequence;
	typename T::iterator	it;
	int						last;
	int 					val;
	
	generateSequenceJacob(jacobSequence, size);
	
	last = 1;
	it = jacobSequence.begin();
	while(it != jacobSequence.end())
	{
		val = *it;
		while(val > last)
		{
			positions.push_back(val - 1);
			val--;
		}
		last = *it;
		it++;
	}
	last++;
	while (last <= size)
	{
		positions.push_back(last - 1);
		last++;
	}
}
/* -- End -- Generate positions to use in 'Binary Insertion' -- */

/* -- Start binarySearchInsertion --- */
// https://en.wikipedia.org/wiki/Binary_search

template <typename T>
static void	binarySearchInsertion(T & container, int target)
{
	size_t	left;
	size_t	mid;
	size_t	right;

	left = 0;
	right = container.size() - 1;
	while (!(left == 0 && right == 0 && mid == 0) && left <= right)
	{
		mid = (left + right) / 2;
		if (container[mid] < target)
			left = mid + 1;
		else if (container[mid] > target && mid > 0)
      		right = mid - 1;
		else if (container[mid] > target && mid == 0)
			right = 0;
  	}
 	if (left < container.size())
		container.insert(container.begin() + left, target);
 	else
		container.push_back(target);
}

/* -- End binarySearchInsertiont --- */
/*
 * Ford-John Algorithm
 *
 * 1- Create Pairs ( for odd size the last value is associated to oddValue)
 * 2- Sort each pair values as (hight, low) pair (don´t look another pair)
 * 3- Sort all pair in ascendent order by low value of each pair.
 * 4- Push first number of the pair to sorted vector
 * 5- Push second number of pairs in the right place of sorted vector using Jacobsthal and Binary Search Insertion
 */

/*
 * T container type : <int>
 * U Container type : std::pair<int, int>
 */

template <typename T, typename U>
T	fordJohnAlgorithm(T & unsortCont, U & pairsCont)
{
	T						sortedCont;
	T						positions;
	typename T::iterator	it;
	typename U::iterator	itp;
	int						oddValue;

	oddValue = ODD_DEFAULT_VAL;
		
	if (isContainerSorted(unsortCont))
	{
		sortedCont = unsortCont;
		return (sortedCont);
	}

	//1- Create pairsCont
	it = unsortCont.begin();
	while(it !=unsortCont.end())
	{
		if (it < unsortCont.end() - 1)
		{
			pairsCont.push_back(std::make_pair(*it, *(it + 1)));
			it++;
		}
		else
			oddValue = *it;
		it++;
	}
	//2- Sort each pair as (hight, low)
	itp = pairsCont.begin();
	while(itp !=pairsCont.end())
	{
		if ((*itp).first < (*itp).second)
			std::swap((*itp).first, (*itp).second);
		itp++;
	}

	//3- Sort pairsCont by first number
	mergeSort(pairsCont, 0 , pairsCont.size() - 1);

	//4- Push first number of the pair to sorted vector
	itp = pairsCont.begin();
	while(itp !=pairsCont.end())
	{
		sortedCont.push_back((*itp).first);
		itp++;
	}

	//5- Push second number of pairs in the right place of sorted vector using Jacobsthal and Binary Search Insertion
	//5-1 Generating positions used in 'Binary Search Insertion'
	generatePositions(positions, pairsCont.size());

	itp = pairsCont.begin();
	it = positions.begin();
	// 5-2 the second value of the first pair in 'Pairs Container' sorted by first element of pairs is the lower value for the actual 'sortedCont'. So can be put as initial value in 'sortedCont'
	sortedCont.insert(sortedCont.begin(),(*itp).second);
	// 5-3 Put the rest of seconds values in the sorted container 
	while (it != positions.end())
	{
		binarySearchInsertion(sortedCont, (*(itp + *it)).second); 
		it++;
	}
	//5-4 Insert the odd value 
	if (oddValue > ODD_DEFAULT_VAL) 
		binarySearchInsertion(sortedCont, oddValue); 
	return (sortedCont);
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
