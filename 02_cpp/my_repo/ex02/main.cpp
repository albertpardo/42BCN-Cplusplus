/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:11:46 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/15 15:16:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	

	std::cout << "\n---- Other test 1 ----" << std::endl;
	std::cout << b << " == " << b << "? " << (b == b) << std::endl; 
	std::cout << a << " == " << b << "? " << (a == b) << std::endl; 
	std::cout << b << " != " << b << "? " << (b != b) << std::endl; 
	std::cout << a << " != " << b << "? " << (a != b) << std::endl; 
	std::cout << a << " < " << b << "? " << (a < b) << std::endl; 
	std::cout << a << " <= " << a << "? " << (a <= a) << std::endl; 
	std::cout << a << " >= " << a << "? " << (a >= a) << std::endl;

	Fixed 	c(a);
	std::cout << "\n---- Other test 2 ----" << std::endl;
	std::cout << "a=" << a << std::endl;
	std::cout << "c=" << c << std::endl;
	std::cout << "a == c ? " << (a == c) << std::endl;
	++c;
	std::cout << "a == ++c ? " << (a == c) << std::endl;

	Fixed	d(30.345f);
	std::cout << "\n---- Other test 3 ----" << std::endl;
	Fixed	e(d / 2);
	Fixed	f(d * 2);
	std::cout << "d        = " << d << std::endl;
	std::cout << "e(d / 2) = " << e << std::endl;
	std::cout << "f(d * 2) = " << f << std::endl;
	
	Fixed	g(5);
	Fixed	h(2.1f);
	std::cout << "\n---- Other test 4 ----" << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "h = " << h << std::endl;
	std::cout << "h = " << h.toInt() << std::endl;
	std::cout << "g + h = " << g + h << std::endl;
	std::cout << "g - h = " << g - h << std::endl;

	return (0);
}
