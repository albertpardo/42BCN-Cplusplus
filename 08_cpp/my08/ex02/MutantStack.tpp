/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:12:14 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/15 09:12:17 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * An example why use 'MutantStack<T>::' as format see :
 * https://www.geeksforgeeks.org/templates-cpp/
 */


/* --- Ortodox public functions --- */

template <typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>() 
{
	std::cout << "\t--Mutant stack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack & oth) : std::stack<T>( oth )
{
	std::cout << "\t--Mutant stack copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=( const MutantStack & oth)
{
	std::cout << "\t--Mutant stack equal operator called" << std::endl;
	if (this != &oth)
		std::stack<T>::operator=(oth);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack( void )
{
	std::cout << "\t--Mutant stack destructor called" << std::endl;
}

/* --- Public functions --- */

/*
 * ------------
 * stack Info:
 * ------------
 *
 * - 'Container c' is a Public Member object  (see https://en.cppreference.com/w/cpp/container/stack)
 */

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin( void )
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end( void )
{
	return (this->c.end());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator	MutantStack<T>::rbegin( void )
{
	return (this->c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator	MutantStack<T>::rend( void )
{
	return (this->c.rend());
}
