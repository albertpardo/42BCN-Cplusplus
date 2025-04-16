/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:03:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/18 14:55:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "PmergeMe.hpp"

int	 main( int argc, char **argv )
{
	std::vector<int>	unsortedVector;
	std::vector<int>	sortedVector;
	std::deque<int>		unsortedDeque;
	std::deque<int>		sortedDeque;
	clock_t				t;

	if (argc > 1)
	{
		try
		{
			std::cout << std::fixed; 
			t = clock();
			unsortedVector = strIntToContainer< std::vector<int> >(argv);
			sortedVector = mergeInsertSortVector(unsortedVector);
			t = clock() - t;
			std::cout << "Before: ";
			printContainer(unsortedVector);
			std::cout << "After:  ";
			printContainer(sortedVector);
			std::cout << "Time to process a range of " << unsortedVector.size() << " elements with std::vector : " << static_cast<double>(t)/CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
			t = clock();
			unsortedDeque = strIntToContainer< std::deque<int> >(argv);
			sortedDeque = mergeInsertSortDeque(unsortedDeque);
			t = clock() - t;
			std::cout << "Time to process a range of " << unsortedDeque.size() << " elements with std::deque  : " << static_cast<double>(t)/CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
			if (isContainerSorted(sortedVector) && sortedVector.size() == unsortedVector.size())
				std::cout << "--- Vector correctly sorted!"<< std::endl;
			if ( isContainerSorted(sortedDeque) && sortedDeque.size() == unsortedDeque.size())
				std::cout << "--- Deque correctly sorted!" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: Invalid number of arguments. Use: ./PmergeMe [number_sequence]" << std::endl;

	return (0);
}
