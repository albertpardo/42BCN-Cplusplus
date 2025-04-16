/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:14:53 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/12 10:14:58 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point( void );
		Point( const float x, const float y);
		Point( const Point& point );
		Point&	operator = ( const Point& point );
		~Point( void );

		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

#endif
