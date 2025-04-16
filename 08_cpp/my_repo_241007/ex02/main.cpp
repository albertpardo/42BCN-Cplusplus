/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:03:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/21 18:46:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

static void	subjectMainMutant( void )
{
	MutantStack<int> mstack;
	
	std::cout << "**** Using MutantStack<int> ---" << std::endl;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << std::endl;
}

static void	subjectMainList( void )
{
	std::list<int> mstack;
	
	std::cout << "**** Using list<int> ---" << std::endl;
	mstack.push_back(5);
	mstack.push_back(17);
	
	std::cout << mstack.back() << std::endl;
	
	mstack.pop_back();
	
	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::list<int> s(mstack);

	std::cout << std::endl;
}

static void	testMutantCopy( void )
{
	MutantStack<int> mstack;
	
	std::cout << "**** Using testMutantCopy ---" << std::endl;
	mstack.push(5);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int> mstackCopy(mstack);

	mstackCopy.push(3000);

	MutantStack<int>::iterator it = mstackCopy.begin();
	MutantStack<int>::iterator ite = mstackCopy.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
}

static void	testMutantEqual( void )
{
	MutantStack<int> mstack;
	
	std::cout << "**** Using testMutantCopy ---" << std::endl;
	mstack.push(5);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int> mstackEqual;

	mstackEqual = mstack;

	mstackEqual.push(3000);

	MutantStack<int>::iterator it = mstackEqual.begin();
	MutantStack<int>::iterator ite = mstackEqual.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
}

static void	testMutantReverse( void )
{
	MutantStack<int> mstack;
	
	std::cout << "**** Using testMutantReverse ---" << std::endl;
	mstack.push(5);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Normal iteration :" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << "Reverse iteration :" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << std::endl;
}

int	 main( void )
{
	subjectMainMutant();
	std::cout << std::endl;
	subjectMainList();
	std::cout << std::endl;
	testMutantCopy();
	std::cout << std::endl;
	testMutantEqual();
	std::cout << std::endl;
	testMutantReverse();
	return (0);
}
