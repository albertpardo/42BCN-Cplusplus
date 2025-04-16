/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:47:42 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/24 12:13:14 by apardo-m         ###   ########.fr       */
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

int jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

/*
 * mergeInsertSort Vector
 *
 * Use Ford-Johnson algorithm with a Vector container
 */

std::vector<int>	mergeInsertSortVector(std::vector<int> & unsortVec)
{
	std::vector<int>					sortedVec;
	std::vector< std::pair<int, int> >	pairsVec;

	sortedVec = fordJohnAlgorithm(unsortVec, pairsVec);
	return (sortedVec);


}

/*
 * mergeInsertSortDeque
 *
 * Use Ford-Johnson algorithm with a Deque container
 */

std::deque<int>	mergeInsertSortDeque(std::deque<int> & unsortDeque)
{
	std::deque<int>								sortedDeque;
	std::deque< std::pair<int, int> >			pairsDeque;

	sortedDeque = fordJohnAlgorithm(unsortDeque, pairsDeque);
	return (sortedDeque);
}
