/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:11:37 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/15 16:03:39 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int numInt)
{
//	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(numInt << this->_fracBits);
}

Fixed::Fixed(const float numFloat)
{
//	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(numFloat * (1 << this->_fracBits)));
}

Fixed::Fixed(const Fixed& fix)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}
		
Fixed& Fixed::operator = (const Fixed& fix)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->_rawBits = fix.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
//	std::cout << "Destructor called" << std::endl;
}

// Operators : >, < , >= , <=, ==, !=

bool Fixed::operator > ( const Fixed& fix ) const
{
	return(this->getRawBits() > fix.getRawBits());
}

bool Fixed::operator < ( const Fixed& fix ) const
{
	return(this->getRawBits() < fix.getRawBits());
}

bool Fixed::operator >= ( const Fixed& fix ) const
{
	return(this->getRawBits() >= fix.getRawBits());
}

bool Fixed::operator <= ( const Fixed& fix ) const
{
	return(this->getRawBits() <= fix.getRawBits());
}

bool Fixed::operator==( const Fixed& fix ) const
{
	return(this->getRawBits() == fix.getRawBits());
}

bool Fixed::operator != ( const Fixed& fix ) const
{
	return(this->getRawBits() != fix.getRawBits());
}

// Operators : +, - , * , /

Fixed	Fixed::operator + ( const Fixed& fix )
{
	Fixed tmp(this->toFloat() + fix.toFloat());
	return (tmp);
}

Fixed	Fixed::operator - ( const Fixed& fix )
{
	Fixed tmp(this->toFloat() - fix.toFloat());
	return (tmp);

}

Fixed	Fixed::operator * ( const Fixed& fix )
{
	Fixed tmp(this->toFloat() * fix.toFloat());
	return (tmp);
}

Fixed	Fixed::operator / ( const Fixed& fix )
{
	Fixed tmp(this->toFloat() / fix.toFloat());
	return (tmp);
}

// (pre-increment and post-increment, pre-decrement and post-decrement) operators
// See:
// https://www.ibm.com/docs/en/xl-c-and-cpp-aix/16.1?topic=only-overloading-increment-decrement-operators-c
// https://www.sanfoundry.com/cpp-program-overloads-pre-and-post-increment-operators/

Fixed&	Fixed::operator ++ ( void )
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed&	Fixed::operator -- ( void ) 
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}


// See post-increment:
// https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/
//
// The operator symbol for both prefix(++i) and postfix(i++) are the same. Hence, we need two different function definitions to distinguish between them.
// This is achieved by passing a dummy int parameter in the postfix version.

Fixed	Fixed::operator ++ ( int )
{
	Fixed	tmp = *this;

	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed	Fixed::operator -- ( int ) 
{
	Fixed	tmp = *this;

	this->setRawBits(this->getRawBits() - 1);
	return (tmp);

}

// Public Functions

int Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}
		
void Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}	

/*
 * Fixed foint to float:
 *    (float)fixed_point_number / (1 << 8)  // Where 8 is Exponed for fixed point
 *
 * Better use C++ format :
 *    static_cast<float> fixed_point_number / (1 << 8)  // Where 8 is Exponed for fixed point
 *
 * See:
 * https://medium.com/@oumaimafisaoui/floating-and-fixed-point-representation-in-c-what-is-going-on-b71af54718a5
 *
 * C++ casting:
 * https://cplusplus.com/articles/iG3hAqkS/
 *
 * C++ cast VS C cast:
 * https://stackoverflow.com/questions/1609163/what-is-the-difference-between-static-cast-and-c-style-casting
 */

float Fixed::toFloat( void ) const
{
	return (static_cast<float> (this->getRawBits()) / (1 << this->_fracBits));
}

int Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->_fracBits);
}

Fixed&	Fixed::min( Fixed &fix1, Fixed &fix2)
{
	if ( fix1.getRawBits() <= fix2.getRawBits() )
		return (fix1);
	return (fix2);
}

Fixed&	Fixed::max( Fixed &fix1, Fixed &fix2)
{
	if ( fix1.getRawBits() > fix2.getRawBits() )
		return (fix1);
	return (fix2);
}

const Fixed&   Fixed::min( const Fixed &fix1, const Fixed &fix2)
{
	if ( fix1.getRawBits() <= fix2.getRawBits() )
		return (fix1);
	return (fix2);
}

const Fixed&   Fixed::max( const Fixed &fix1, const Fixed &fix2)
{
	if ( fix1.getRawBits() > fix2.getRawBits() )
		return (fix1);
	return (fix2);
}

/*
 *  Overloading the << Operator for Your Own Classes
 * https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
 */

std::ostream& operator << (std::ostream& out, const Fixed &nb)
{
	return (out << nb.toFloat());
}
