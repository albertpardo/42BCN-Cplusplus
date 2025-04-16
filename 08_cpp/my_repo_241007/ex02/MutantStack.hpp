/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:12:14 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/21 18:26:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/*
 * ---------------------------------
 * typename concepts with iterators
 * ---------------------------------
 *
 * Problems with : 'dependant name (type)' because change in execution
 *
 *  See my explanations at the end of this file
 *
 *  References:
 *  ---------
 *
 *  'use of typename keyword'
 *  https://cplusplus.com/forum/general/122765/
 *
 *  'A Description of the C++ typename keyword'
 *  https://pages.cs.wisc.edu/~driscoll/typename.html
 *  
 *  'Automatic Return Type'
 *  https://www.modernescpp.com/index.php/automatic-return-type/
 *
 */

/*
 * see iterators types on 'Member maps' in :
 * https://cplusplus.com/reference/stl/
 *
 * - iterators (c++98): begin, end , rbegin, rend
 * - const iterator (c++11) : cbegin, cend, crbegin, crend
 *
 * ------------
 * stack Info:
 * ------------
 *
 * template <class T, class Container = deque<T> > class stack;
 *   'deque' is used as default value for 'Class container'
 *   other containers : 'vector', 'list'
 * Examples :
 *  stack<T>   ( container = deque)
 *  stack<T, list>  ( container = list)
 *  stack<T, vector>  ( container = vector)
 *
 * -----------
 *  list info  (as example for container.)
 *  https://cplusplus.com/reference/list/list/
 *  ----------
 *  in member type has the next related with 'iterators' 
 *  - iterator			('bidirectional iterator')
 *  - const_iterator 	('bidirectional iterator')
 *  - const_reverse_iterator ('reverse_iterator<iterator>')
 *  - reverse_iterator	('reverse_iterator<iterator>')
 * 
 *  -------
 *  'bidirectional iterator' info:
 *  https://cplusplus.com/reference/iterator/BidirectionalIterator/
 *  -------
 *
 *  -------
 *  'reverse_iterator<iterator>' info:
 *  https://cplusplus.com/reference/iterator/BidirectionalIterator/
 *  -------
 *
 */

#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>	
{
	public:
		MutantStack( void );
		MutantStack( const MutantStack & oth);
		MutantStack & operator=( const MutantStack & oth);
		~MutantStack( void );

		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

 		iterator			begin( void );
 		iterator			end( void );
 		reverse_iterator	rbegin( void );
 		reverse_iterator	rend( void );
		
};

#include "MutantStack.tpp"

#endif


/*
 * ---------------------------------
 * typename concepts with iterators
 * ---------------------------------
 *
 *  In 'MutantStack Class' we define a 'begin()' that returns an 'iterator' from container 'stack':
 *
 * ```
 *  std::stack<T>::container_type::iterator	begin( void );
 * ```
 *
 * Where ( C++98 don´t understand type):
 *  'std::stack<T>::container_type::iterator' is a typo (similar concept as 'int' or 'float'  type
 *
 * 'typename' is used , so c++98 undertand that is a type
 *
 * ```
 *  typename std::stack<T>::container_type::iterator	begin( void );
 * ```
 *
 */
