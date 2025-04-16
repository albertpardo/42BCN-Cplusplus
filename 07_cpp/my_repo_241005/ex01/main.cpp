/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:04:58 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/04 14:17:08 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define SIZE1 5
#define SIZE2 2
#define SIZE3 4

template <typename T>
void	multDos(T &item)
{
	item = item * 2;
}

template <typename T>
void	putItem(T & item)
{
	std::cout << item << std::endl;
}

int	main( void )
{
	int		intArray[SIZE1] = {1, 2, 3, 4, 5};
	float	floatArray[SIZE2] = {1.1, 2.2};
	char	charArray[SIZE3] = {'a', 'b', 'c', 'd'};
	int		*p = NULL;

	std::cout << "intArray values :" << std::endl;
	::iter(intArray, SIZE1, putItem);
	std::cout << std::endl;
	std::cout << "floatArray values :" << std::endl;
	::iter(floatArray, SIZE2, putItem);
	std::cout << std::endl;
	std::cout << "charArray values :" << std::endl;
	::iter(charArray, SIZE3, putItem);
	std::cout << std::endl;
	std::cout << "Null Array :" << std::endl;
	::iter(p, SIZE3, putItem);
	return (0);
}
