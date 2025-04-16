/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:19:23 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/04 15:13:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template < typename Array>
static void putArrayPos( unsigned int pos,const Array & array) 
{
	try
	{
		std::cout << array[pos] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}		
}

static void defaultArray( void )
{
	Array<int>	defaultArrayNum;

	std::cout << "'defaultArrayNum' size = " << defaultArrayNum.size() << std::endl;
	std::cout << "'defaultArrayNum' is Null ? : " ;
	putArrayPos( 0, defaultArrayNum);
}

template <typename Array>
static void	putArray(const Array & array)
{
	unsigned int	i;

	i = -1;
	try
	{
		while (++i < array.size())
			std::cout << "Pos i = " << i << ", " << array[i] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}	
}

static void numbersArray( unsigned int n )
{
	unsigned int	i;
	Array<int>		numbers(n);
	
	std::cout << "--- Default values of 'numbers' with size=" << n << std::endl;
	putArray(numbers);
	std::cout << std::endl;

	// Put values on 'numbers'
	i = -1;
	while (++i < numbers.size())
		numbers[i] = i;
	std::cout << "--- 'numbers' with new values ---" << std::endl;
	putArray(numbers);
	std::cout << std::endl;
	
	// positive out of range index
	i = numbers.size() + 1;
	std::cout << "numbers[" << i << "] = ";
	putArrayPos(i, numbers);
	std::cout << std::endl;
}

static void	stringArray(void)
{
	unsigned int		size = 4;
	Array<std::string>	arrayString(size);

	arrayString[0] = "Cero";
	arrayString[1] = "Uno";
	arrayString[2] = "Dos";
	arrayString[3] = "Tres";

	std::cout << "--- 'arrayString' values ---" << std::endl;
	putArray(arrayString);
	std::cout << std::endl;

	std::cout << "--- Constructor copy test from 'arrayString' ---" << std::endl;
	Array<std::string>	arrayCopy(arrayString);
	std::cout << ">--- 'arrayCopy' values ---" << std::endl;
	putArray(arrayCopy);
	std::cout << std::endl;
}

static void	equalTest( void )
{
	Array<double>	arrayFloat1(4);
	Array<double>	arrayFloat2;

	arrayFloat1[0] = 2.4f;
	arrayFloat1[1] = 25.1f;
	arrayFloat1[2] = -3.1f;
	arrayFloat1[3] = 42.24f;

	std::cout << "'arrayFloat2' : ";
	putArrayPos(0, arrayFloat2);
	std::cout << std::endl;

	arrayFloat2 = arrayFloat1;
	std::cout << "--- After 'arrayFloat2 = arrayFloat1' , 'arrayFloat12' values are:" << std::endl;
	putArray(arrayFloat2);
	std::cout << std::endl;
}

static void outRange( void )
{
	Array<double>	arrayFloat1(4);

	arrayFloat1[0] = 2.4f;
	arrayFloat1[1] = 25.1f;
	arrayFloat1[2] = -3.1f;
	arrayFloat1[3] = 42.24f;

	std::cout << "--- Access outside Array limits :" << std::endl;
	try
	{
		std::cout << "arrayFloat1[-1] = ";
		arrayFloat1[-1] = 0.4f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "arrayFloat1[20] = ";
		arrayFloat1[20] = 0.4f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main ( void )
{

	std::cout << "=== DefaultArray() ===" << std::endl;
	defaultArray();	
	std::cout << std::endl;
	std::cout << "=== numbersArray(3) ===" << std::endl;
	numbersArray(3);
	std::cout << std::endl;
	std::cout << "=== stringArray() ===" << std::endl;
	stringArray();
	std::cout << std::endl;
	std::cout << "=== equalTest() ===" << std::endl;
	equalTest();
	std::cout << std::endl;
	std::cout << "=== equalTest() ===" << std::endl;
	outRange();
	return (0);
}
