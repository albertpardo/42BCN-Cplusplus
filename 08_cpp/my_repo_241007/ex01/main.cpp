/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:03:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/05 14:59:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include "Span.hpp"

#define MAX_SIZE 15000

static void myAddNumber(Span & sp, unsigned int n)
{
	try
	{
		sp.addNumber(n);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	subjectMain( void )
{
	Span	sp = Span(5);

	std::cout << "--- subjectMain() ---" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

static void	testCopyConstructor( void )
{
	Span	sp = Span(5);

	std::cout << "--- testCopyConstructor() ---" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	Span	sp2 = Span(sp);
	std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
	std::cout << "sp2.longestSpan()  = " << sp2.longestSpan() << std::endl;
	std::cout << std::endl;
}

static void	testOperatorEqual( void )
{
	Span	sp = Span(5);
	Span	sp3;

	std::cout << "--- testOperatorEqual() ---" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp3 = sp;
	std::cout << "sp3.shortestSpan() = " << sp3.shortestSpan() << std::endl;
	std::cout << "sp3.longestSpan()  = " << sp3.longestSpan() << std::endl;
	std::cout << std::endl;
}

static void	putShortestLongestCheckErr( Span & sp, std::string msg )
{

	std::cout << msg << std::endl;
 	try
	{
		std::cout << "sp.shortestSpan() = " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "sp.longestSpan()  = " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	testNoEnoughtValuesForShortestLongest( void )
{
	Span	sp = Span(1);

	sp.addNumber(6);
	putShortestLongestCheckErr(sp, "--- testNoEnoughtValuesForShortestLongest() ---");
}

static void	testFullSpan( void )
{
	Span	sp = Span(2);

	std::cout << "--- testFullSpan() ---" << std::endl;
	myAddNumber(sp, 3);
	myAddNumber(sp, 6);
	myAddNumber(sp, 9);
	std::cout << std::endl;
}

static void	testInsertLotIntsOne( unsigned int size )
{
	unsigned int 	i = 0;
	Span			sp = Span(size);

	while (i < size)
	{
		sp.addNumber(i);
		i++;
	}
	putShortestLongestCheckErr(sp, "--- testInsertLotIntsOne() using Span::addNumber()---");
}

static void	testInsertLotIntsTwo( unsigned int size )
{
	unsigned int		i;
	std::vector<int>	v;
	Span				sp = Span(size);

	i = 0;
	while (i < size)
	{
		v.push_back(i);
		i++;
	}
	sp.addManyNumber(v.begin(), v.end());
	putShortestLongestCheckErr(sp, \
			"--- testInsertLotIntsTwo() using Span::addManyNumber() with vector iterator ---");
}

static void	testInsertLotIntsThree( unsigned int size )
{
	unsigned int		i;
	int					arrayInt[size];
	Span				sp = Span(size);

	i = 0;
	while (i < size)
	{
		arrayInt[i] = i;
		i++;
	}
	sp.addManyNumber(arrayInt, arrayInt + size);
	putShortestLongestCheckErr(sp, \
		"--- testInsertLotIntsThree() using Span::addManyNumber() with 'int array' as vector ---");
}

static void	testInsertLotIntsThreeWithError( unsigned int size )
{
	unsigned int		i;
	int					arrayInt[size];
	Span				sp = Span(size);

	i = 0;
	while (i < size)
	{
		arrayInt[i] = i;
		i++;
	}		
	sp.addNumber(100000);
	std::cout << "--- testInsertLotIntsThreeWithError() using Span::addManyNumber() with 'int array' as vector ---" << std::endl;
	try
	{
		sp.addManyNumber(arrayInt, arrayInt + size);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	putShortestLongestCheckErr(sp, "  - testInsertLotIntsThreeWithError() : shortestSpan , longestSpan-");
}

int	 main( void )
{
	subjectMain();
	testCopyConstructor();
	testOperatorEqual();
	testFullSpan();
	testNoEnoughtValuesForShortestLongest();
	testInsertLotIntsOne(MAX_SIZE);
	testInsertLotIntsTwo(MAX_SIZE);
	testInsertLotIntsThree(MAX_SIZE);
	testInsertLotIntsThreeWithError(MAX_SIZE);
	return (0);
}
