/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:13:50 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/12 11:19:21 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed absFixed ( Fixed num )
{
	if (num < 0)
		return (num * -1.0f);
	return (num);
}

/*
 *	see :
 * https://www.cuemath.com/geometry/area-of-triangle-in-coordinate-geometry/
 * https://www.fisicalab.com/apartado/producto-vectorial
 * https://www.fisicalab.com/ejercicio/691
 */

static Fixed areaTriangle(Point const a, Point const b, Point const c)
{
	Fixed   crossProduct( a.getX() * (b.getY() - c.getY()) \
						+ b.getX() * (c.getY() - a.getY()) \
						+ c.getX() * (a.getY() - b.getY()));

	return (absFixed(crossProduct) / 2);
}

/*
static void printFixedFloat( Fixed fix, std::string msg)
{
	std::cout << msg << fix.toFloat() << std::endl;
}
*/

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea(areaTriangle( a, b, c));
	Fixed pabArea(areaTriangle( a ,b, point));
	Fixed pacArea(areaTriangle( a, c, point));
	Fixed pbcArea(areaTriangle( b, c, point));
	Fixed minArea;

	++minArea;
/*
	printFixedFloat(abcArea, "abcArea = ");
	printFixedFloat(pabArea, "pabArea = ");
	printFixedFloat(pacArea, "pacArea = ");
	printFixedFloat(pbcArea, "pbcArea = ");
	printFixedFloat(minArea, "minArea = ");

	std::cout << "Diff areas = " << absFixed(abcArea - ( pabArea + pacArea + pbcArea)) << std::endl;
*/

	if (pabArea <= minArea || pacArea <= minArea || pbcArea <= minArea)
		return (false);
	if (absFixed(abcArea - ( pabArea + pacArea + pbcArea)) <= minArea)
		return (true);
	return (false);
}
