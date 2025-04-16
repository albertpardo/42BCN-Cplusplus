/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:13:40 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/12 10:13:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) 
{
}

Point::Point( const float x, const float y)  : _x(x), _y(y)
{
}

Point::Point( const Point& oldP ) : _x(oldP.getX()), _y(oldP.getY())
{
}

/*
 * Overload operator = can't no be implemented because _x and _y are constants
 */

Point&	Point::operator = (const Point& oldP)
{
	if (this == &oldP)
		return (*this);
	return (*this);
}

Point::~Point( void )
{
}

Fixed Point::getX( void ) const
{
	return (this->_x);
}

Fixed Point::getY( void ) const
{
	return (this->_y);
}
