/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:47:42 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/24 14:23:57 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "PmergeMe.hpp"

#define ODD_DEFAULT_VAL -1

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
 * returns a jacobsthal value for input 'n' 
 */

static int jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

/* ---------- START : Vector ----------  */

/*---- Start Merge Vector ---*/

static void mergeVector(std::vector< std::pair<int, int> > & vec, int left, int mid, int right)
{
    int i, j, k;

    // Create temporary vector to store order values
    std::vector< std::pair<int, int> > tmp(right - left + 1);
    
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


// The subarray to be sorted is in the index range [left..right]
static void mergeSortVector(std::vector< std::pair<int, int> > & vec, int left, int right)
{
    if (left < right)
   	{
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSortVector(vec, left, mid);
        mergeSortVector(vec, mid + 1, right);

        // Merge the sorted halves
        mergeVector(vec, left, mid, right);
    }
}

/*---- End Merge Vector ---*/

/* -- Start -- Generate positions to use in 'Binary Insertion' -- */

/*
 * Generate a Jacobsthal sequence starting in 3 based on the size of Container
 * 3, 5 , 11 ,..... 
 *
 */

static void generateSequenceJacobVec(std::vector<int> & jacobSequence, int size)
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

static void generatePositionsVect(std::vector<int> & positions, int size)
{
	std::vector<int>			jacobSequence;
	std::vector<int>::iterator	it;
	int							last;
	int							val;
	
	generateSequenceJacobVec(jacobSequence, size);
	
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

/* -- Start binarySearchInsertionVect --- */
// https://en.wikipedia.org/wiki/Binary_search
//
static void	binarySearchInsertionVect(std::vector<int> & cont, int target)
{
	size_t	left;
	size_t	mid;
	size_t	right;

	left = 0;
	right = cont.size() - 1;
	while (!(left == 0 && right == 0 && mid == 0) && left <= right)
	{
		mid = (left + right) / 2;
		if (cont[mid] < target)
			left = mid + 1;
		else if (cont[mid] > target && mid > 0)
      		right = mid - 1;
		else if (cont[mid] > target && mid == 0)
			right = 0;
  	}
 	if (left < cont.size())
		cont.insert(cont.begin() + left, target);
 	else
		cont.push_back(target);
}

/* -- End binarySearchInsertionVect --- */

/*
 * mergeInsertSort Vector
 *
 * 1- Create Pairs ( for odd size the last value is associated to oddValue) 
 * 2- Sort each pair values as (low,hight) pair (don´t look another pair)
 * 3- Sort all pair in ascendent order by low value of each pair.
 * 4- Push first number of the pair to sorted vector
 * 5- Push second number of pairs in the right place of sorted vector using Jacobsthal and Binary Search Insertion
 */

std::vector<int>	mergeInsertSortVector(std::vector<int> & unsortVec)
{
	std::vector<int>								sortedVec;
	std::vector< std::pair<int, int> >				pairsVec;
	std::vector<int>								positions;
	std::vector<int>::iterator						it;
	std::vector< std::pair<int, int> >::iterator	itp;
	int												oddValue;

	oddValue = ODD_DEFAULT_VAL;
		
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
			oddValue = *it;
		it++;
	}
	//2- Sort each pair as (hight, low)
	itp = pairsVec.begin();
	while(itp !=pairsVec.end())
	{
		if ((*itp).first < (*itp).second)
			std::swap((*itp).first, (*itp).second);
		itp++;
	}

	//3- Sort pairsVec by first number
	mergeSortVector(pairsVec, 0 , pairsVec.size() - 1);
	//4- Push first number of the pair to sorted vector
	itp = pairsVec.begin();
	while(itp !=pairsVec.end())
	{
		sortedVec.push_back((*itp).first);
		itp++;
	}

	//5- Push second number of pairs in the right place of sorted vector using Jacobsthal and Binary Search Insertion
	//5-1 Generating positions used in 'Binary Search Insertion'
	generatePositionsVect(positions, pairsVec.size());

	itp = pairsVec.begin();
	it = positions.begin();
	// 5-2 the second value of the first pair in 'Pairs Container' sorted by first element of pairs is the lower value for the actual 'sortedVec'. So can be put as initial value in 'sortedVec'
	sortedVec.insert(sortedVec.begin(),(*itp).second);
	// 5-3 Put the rest of seconds values in the sorted container 
	while (it != positions.end())
	{
		binarySearchInsertionVect(sortedVec, (*(itp + *it)).second); 
		it++;
	}
	//5-4 Insert the odd value 
	if (oddValue > ODD_DEFAULT_VAL) 
		binarySearchInsertionVect(sortedVec, oddValue); 
	return (sortedVec);
}
/* ---------- END : Vector ----------  */

/* ---------- START : Deque ----------  */
/*---- Start Merge Deque ---*/

static void mergeDeque(std::deque< std::pair<int, int> > & deq, int left, int mid, int right)
{
    int i, j, k;

    // Create temporary deque to store order values
    std::deque< std::pair<int, int> > tmp(right - left + 1);
    
	// Merge to tmp in sort way
    i = left;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= right)
	{
		if (deq[i] <= deq[j])
            tmp[k++] = deq[i++];
		else
            tmp[k++] = deq[j++];
    }

	// Copy the remaining elements in first half until 'mid' pos
	while (i <= mid)
		tmp[k++] = deq[i++];

    // Copy the remaining elements in second half  until 'right' pos
    while (j <= right)
		tmp[k++] = deq[j++];

	//Copy sorted values from 'tmp' to original container
	for (int z = 0; z < k; z++)
		deq[left + z] = tmp[z];
}


// The subarray to be sorted is in the index range [left..right]
static void mergeSortDeque(std::deque< std::pair<int, int> > & vec, int left, int right)
{
    if (left < right)
   	{

        // Calculate the midpoint
        int mid = (right + left) / 2;

        // Sort first and second halves
        mergeSortDeque(vec, left, mid);
        mergeSortDeque(vec, mid + 1, right);

        // Merge the sorted halves
        mergeDeque(vec, left, mid, right);
    }
}

/*---- End Merge Deque ---*/

/* -- Start -- Generate positions to use in 'Binary Insertion' -- */

/*
 * Generate a Jacobsthal sequence starting in 3 based on the size of Container
 * 3, 5 , 11 ,..... 
 *
 */

static void generateSequenceJacobDeque(std::deque<int> & jacobSequence, int size)
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

static void generatePositionsDeque(std::deque<int> & positions, int size)
{
	std::deque<int>				jacobSequence;
	std::deque<int>::iterator	it;
	int							last;
	int							val;
	
	generateSequenceJacobDeque(jacobSequence, size);
	
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

/* -- Start binarySearchInsertionDeque --- */

static void	binarySearchInsertionDeque(std::deque<int> & cont, int target)
{
	size_t	left;
	size_t	mid;
	size_t	right;

	left = 0;
	right = cont.size() - 1;
	while (!(left == 0 && right == 0 && mid == 0) && left <= right)
	{
		mid = (left + right) / 2;
		if (cont[mid] < target)
			left = mid + 1;
		else if (cont[mid] > target && mid > 0)
      		right = mid - 1;
		else if (cont[mid] > target && mid == 0)
			right = 0;
  	}
 	if (left < cont.size())
		cont.insert(cont.begin() + left, target);
 	else
		cont.push_back(target);
}

/*
 * mergeInsertSortDeque
 *
 * 1- Create Pairs ( for odd size the last value is associated to oddValue)
 * 2- Sort each pair values as (low,hight) pair (don´t look another pair)
 * 3- Sort all pair in ascendent order by low value of each pair.
 * 4- Push first number of the pair to sorted deque
 * 5- Push second number of pairs in the right place of sorted vector using Jacobsthal and Binary Search Insertion
 */

std::deque<int>	mergeInsertSortDeque(std::deque<int> & unsortDeque)
{
	std::deque<int>								sortedDeque;
	std::deque< std::pair<int, int> >			pairsDeque;
	std::deque<int>								positions;
	std::deque<int>::iterator					it;
	std::deque< std::pair<int, int> >::iterator	itp;
	int											oddValue;
		
	oddValue = ODD_DEFAULT_VAL;

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
			oddValue = *it;
		it++;
	}

	//2- Sort each pair as (low, hight)
	itp = pairsDeque.begin();
	while(itp !=pairsDeque.end())
	{
		if ((*itp).first < (*itp).second)
			std::swap((*itp).first, (*itp).second);
		itp++;
	}

	//3- Sort pairsDeque set by first number
	mergeSortDeque(pairsDeque, 0 , pairsDeque.size() - 1);

	//4- Push first number of the pair to sorted deque
	itp = pairsDeque.begin();
	while(itp !=pairsDeque.end())
	{
			sortedDeque.push_back((*itp).first);
		itp++;
	}

 	// 5- Push second number of pairs in the right place of sorted vector using Jacobsthal and Binary Search Insertion
	//5-1 Generating positions used in 'Binary Search Insertion'
	generatePositionsDeque(positions, pairsDeque.size());

	itp = pairsDeque.begin();
	it = positions.begin();
	// 5-2 the second value of the first pair in 'Pairs Container' sorted by first element of pairs is the lower value for the actual 'sortedVec'. So can be put as initial value in 'sortedVec'
	sortedDeque.insert(sortedDeque.begin(),(*itp).second);
	// 5-3 Put the rest of seconds values in the sorted container 
	while (it != positions.end())
	{
		binarySearchInsertionDeque(sortedDeque, (*(itp + *it)).second); 
		it++;
	}
	//5-4 Insert the odd value 
	if (oddValue > ODD_DEFAULT_VAL) 
		binarySearchInsertionDeque(sortedDeque, oddValue); 
	return (sortedDeque);
}
/* ---------- END : Deque ----------  */
