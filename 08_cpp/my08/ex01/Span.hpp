/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:11:20 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/19 12:15:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iterator>
#include <vector>

#define ERROR_NO_ENOUGHT "No enought size in Span object for all new elements"

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector <int>	_numbers;

	public:
		Span( void );
		Span( unsigned int size );
		Span( const Span & oth);
		Span & operator=(const Span & oth);
		~Span( void );

		void			addNumber(int num);
		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void );

		template <typename IT>
		void			addManyNumber( IT begin, IT end);
};

/*  The template code is here because '*.tpp' is not in subject */

/*
 * <iterator> : distance()
 * 
 * std::vector<int>.insert(.)  let insert a value range pointed by iterators
 */

template <typename IT>
void	Span::addManyNumber( IT begin, IT end)
{
	if( (std::distance(begin, end) + this->_numbers.size()) <= this->_maxSize)
		this->_numbers.insert(this->_numbers.begin() + this->_numbers.size(), begin, end);
	else
		throw std::logic_error(ERROR_NO_ENOUGHT);
}

#endif
