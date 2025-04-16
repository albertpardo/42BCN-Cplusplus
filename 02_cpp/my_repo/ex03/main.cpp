/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:14:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/12 11:20:51 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define MAXPOINTS 7

bool bsp( Point const a, Point const b, Point const c, Point const point);

static void printPoint( Point const p, std::string msg)
{
	std::cout << msg << "(" << p.getX().toFloat() << " , " << p.getY().toFloat() << ")";
}

static void printBoolText(bool b)
{
	if (b)
		std::cout << "TRUE";
	else
		std::cout << "FALSE";
}

static void testPointInTriangle(Point const a, Point const b, Point const c, Point const p, bool expec)
{
	bool	inTriangle;
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	inTriangle = bsp(a, b, c, p);
	printPoint(p, "Is p = ");
	std::cout << " inside the triangle whith vertices : " << std::endl;
	printPoint(a, "Vertex a = ");
	std::cout << std::endl; 
	printPoint(b, "Vertex b = ");
	std::cout << std::endl; 
	printPoint(c, "Vertex c = ");
	std::cout << "? (Expected : ";
	printBoolText(expec);
	std::cout << ")\n";
	std::cout << "Answer : " ;
	printBoolText(inTriangle);
	std::cout << std::endl;
	if (inTriangle == expec)
		std::cout << "\t---- TEST OK! ----" << std::endl;
	else
		std::cout << "\t---- TEST KO!!!!! ----" << std::endl;
}

static void pointsInTriangle(int maxpoints, Point* triangle, Point* points, bool* expec)
{
	int		i;

	i = -1;
	while (++i < maxpoints)
		testPointInTriangle( triangle[0], triangle[1], triangle[2], points[i], expec[i]);
}

int	main( void )
{

// Test Triangle 1

	Point	triangle1[] = { Point(0.0f, 0.0f), Point(4.0f, 4.0f), Point(8.0f, 0.0f) };
	Point	points1[] = { Point(3.9f, 2.1f), Point(8.0f, 2.1f), Point(2.0f, 1.0f), Point(2.0f, 2.0f), Point(2.0f, 1.99804681f), Point(2.0f, 1.99804682f), Point(-20.0f, -30.0f)};
	bool	expected1[] = { true, false, true, false, true, false, false};
	
	std::cout << "******* Start TESTS triangle1 *******" << std::endl;
	pointsInTriangle(MAXPOINTS, triangle1,  points1, expected1);
	std::cout << "******* End TESTS triangle1 *******\n" << std::endl;

// Test Triangle 2

	Point	triangle2[] = { Point(-4.0f, -4.0f), Point(0.0f, 4.0f), Point(4.0f, 0.0f) };
	Point	points2[] = { Point(0.0f, 0.0f), Point(-1.0f, -1.5f), Point(-3.9f, -3.9f), Point(1.0f, 1.0f), Point(3.0f, 3.1f), Point(-3.2f, 4.1f), Point(-4.0f, -4.0f)};
	bool	expected2[] = { true, true, true, true, false, false, false};
	
	std::cout << "******* Start TESTS triangle2 *******" << std::endl;
	pointsInTriangle(MAXPOINTS, triangle2,  points2, expected2);
	std::cout << "******* End TESTS triangle2 *******\n" << std::endl;

	return (0);
}
