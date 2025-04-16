/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    Array.tpp                                          :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2024/09/14 16:19:39 by apardo-m         #+#     #+#              */
/*    Updated: 2024/09/14 17:28:48 by apardo-m        ###    ########.fr        */
/*                                                                              */
/* **************************************************************************** */

/*
 * C++ Class Templates
 * https://www.programiz.com/cpp-programming/class-templates
 */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <stdexcept>
# include "Array.hpp"

/* --- Ortodox public functions --- */

template <typename T>
Array<T>::Array( void ) : _array(NULL), _size(0)
{
	std::cout << "Array default constructor" << std::endl;
}


/* use of 'new T[n]()' avoid the problem:
 * "Uninitialised value was created by a heap allocation"
 */

template <typename T>
Array<T>::Array( unsigned int n ) : _array(new T[n]()), _size(n)
{
	std::cout << "Array constructor create an array with size " << n << std::endl;
}

template <typename T>
Array<T>::Array (const Array &oth) : _array(new T[oth._size]), _size(oth._size)
{
	unsigned int	i;

	std::cout << "Array copy constructor" << std::endl;
	i = 0;
	while (i < oth._size)
	{
		this->_array[i] = oth._array[i];
		i++;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &oth)
{
	unsigned int	i;

	if (this != &oth)
	{
		delete[] this->_array;
		this->_size = oth._size;
		if (this->_size != 0)
			this->_array = new T[this->_size];
		i = 0;
		while (i < oth._size)
		{
			this->_array[i] = oth._array[i];
			i++;
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array ( void )
{
	std::cout << "Array destructor" << std::endl;
	delete[] this->_array;
}

/* --- Public Functions ---*/


/* 
 *  <stdexcept> : std::out_of_range
 * https://cplusplus.com/reference/stdexcept/?kw=STDEXCEPT 
 */

template <typename T>
T & Array<T>::operator[](const unsigned int index) const
{
	if (this->_array == NULL)
		throw std::out_of_range("Array is NULL");	
	else if (static_cast<unsigned int>(index) >= this->_size)
		throw std::out_of_range("Index out of range");
	else
		return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size( void ) const
{
	return ( this->_size );
}

#endif
