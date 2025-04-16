/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:11:13 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/19 11:33:01 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "Span.hpp"

#define ERROR_FULL_SPAN "Span object is full"
#define ERROR_SMALL_SPAN "Span object size is 0 or 1"
#define ERROR_NO_ENOUGHT "No enought size in Span object for all new elements"

Span::Span( void ) : _maxSize(0) {}

Span::Span( unsigned int size ) : _maxSize(size) {}

Span::Span( const Span & oth)
{
	*this = oth;
}

Span & Span::operator=(const Span & oth)
{
	if (this != &oth)
	{
		this->_maxSize = oth._maxSize;
		this->_numbers = oth._numbers;
	}
	return (*this);
}

Span::~Span( void ) {}

void	Span::addNumber(int num)
{
	if ( this->_numbers.size() < this->_maxSize)
		this->_numbers.push_back(num);
	else
		throw std::logic_error(ERROR_FULL_SPAN);
}

unsigned int	Span::shortestSpan( void )
{
	unsigned int				shortest;
	std::vector<int>::iterator	it;
	unsigned int				diference;

	if (this->_numbers.size() < 2)
		throw std::logic_error(ERROR_SMALL_SPAN);
	shortest = std::numeric_limits<unsigned int>::max();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	it = this->_numbers.begin() + 1;
   	while (it != this->_numbers.end())
	{
		diference = static_cast<unsigned int>(*it - *(it - 1));
		if (diference < shortest)
			shortest = diference;
		it++;
	}
	return (shortest);
}

unsigned int	Span::longestSpan( void )
{
	std::vector<int>::iterator	it_max;
	std::vector<int>::iterator	it_min;

	if (this->_numbers.size() < 2)
		throw std::logic_error(ERROR_SMALL_SPAN);
	it_max = std::max_element(this->_numbers.begin(), this->_numbers.end());
	it_min = std::min_element(this->_numbers.begin(), this->_numbers.end());
	return (static_cast<unsigned int>(*it_max - *it_min));
}
