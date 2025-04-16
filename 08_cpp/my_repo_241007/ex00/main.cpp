/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:03:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/15 11:02:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <vector>
#include "easyfind.hpp"

/*
 * Multiple typename arguments in c++ template? (variadic templates)
 * https://stackoverflow.com/questions/19923353/multiple-typename-arguments-in-c-template-variadic-templates
 * 
 *  Asociative containers : set, multiset, map, multimap
 *  https://en.wikipedia.org/wiki/Associative_containers_(C%2B%2B)
 *
 * Sequence containers : deque, list, queue, vector
 * https://en.wikipedia.org/wiki/Sequence_container_(C%2B%2B)
 */

template <typename TA, typename TB>
void	myEasyfind(const TA & ta, const TB & tb)
{
	try
	{
		easyfind(ta, tb);	
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	 main( void )
{
	std::vector<int>	v;
	std::deque<int>		dq;

	std::cout << "--- Using vector --- " << std::endl;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);	
	std::cout << " 10 is in 'v'?" << std::endl;
	myEasyfind(v, 10);	
	std::cout << std::endl;
	std::cout << " 50 is in 'v'?" << std::endl;
	myEasyfind(v, 50);	
	std::cout << std::endl;
	std::cout << "--- Using deque --- " << std::endl;
	dq.push_back(424242);
	dq.push_back(10000);
	std::cout << "10000 is in 'dq'?" << std::endl;
	myEasyfind(dq, 10000);
	std::cout << std::endl;
	std::cout << "1 is in 'dq'?" << std::endl;
	myEasyfind(dq, 1);
	return (0);
}
