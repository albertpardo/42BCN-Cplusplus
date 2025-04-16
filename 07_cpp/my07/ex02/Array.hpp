/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:53:29 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/15 06:07:42 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

/* C++ Class Templates
 * https://www.programiz.com/cpp-programming/class-templates
 * 
 * C++ Declaring Array using Variable and Returning Array in Function
 * https://medium.com/@antwang/c-arrays-variable-size-and-function-return-26fa58d98ddc
 *
 * Why can templates only be implemented in the header file?
 * https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
 *
 * 'tpp' files  can be include at the end of 'hpp' file
 */

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array( void );
		Array( unsigned int n );
		Array (const Array &oth);
		Array &operator=(const Array &oth);
		~Array ( void );
	
		T &operator[](const unsigned int index) const;
		unsigned int size( void ) const;

};

# include "Array.tpp"

#endif
