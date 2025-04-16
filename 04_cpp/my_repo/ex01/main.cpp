/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:11:05 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 16:29:23 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define TOTAL_ANIMALS 4

static void	testArrayAnimals( void )
{
	int	i;

	std::cout << "/* -------   START test Array animals  ------- */" << std::endl;
	Animal*	animals[TOTAL_ANIMALS];

	std::cout << "\n* NEW animals ----------------------" << std::endl;
	i = -1;
	while ( ++i < TOTAL_ANIMALS)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << "\n* Animals Make sounds ----------------------" << std::endl;
	i = -1;
	while ( ++i < TOTAL_ANIMALS)
	{
		animals[i]->makeSound();
	}
	std::cout << "\n*  DELETE animals -----------------" << std::endl;
	i = -1;
	while ( ++i < TOTAL_ANIMALS)
		delete animals[i];
	std::cout << "/* -------   END test Array animals  ------- */" << std::endl;
}

static void	testAnimalsAssig( void )
{
	std::cout << "/*\n -------   START test Animals assignament  ------- */" << std::endl;
	std::cout << "\n* NEW animals ----------------------" << std::endl;
	Dog	dog1 = Dog();
	Dog* dogP = new Dog(dog1);

	std::cout << "\n* Animals Make sounds ----------------------" << std::endl;
	dog1.makeSound();
	dogP->makeSound();

	std::cout << "\n*  DELETE 'dogP' -----------------" << std::endl;
	delete dogP;
	std::cout << "/* -------   END test Animals assignament (now 'dog1' is going to be destroyed) ------- */" << std::endl;
}

static void testNoShadow( void )
{
	std::cout << "\n/*-------   START testNoShadow  ------- */" << std::endl;
	Dog testDog;
	{
		std::cout << "\n  -- Start inside" << std::endl;
		Dog newDog = testDog;
		std::cout << "  -- End inside" << std::endl;
	}
	std::cout << "-- returned to testShadow" << std::endl;
	std::cout << "/*-------   END testNoShadow  ------- */" << std::endl;
}


int main( void )
{
	testArrayAnimals();
	testAnimalsAssig();
	testNoShadow( );

	std::cout << "\n #### THE END ####" << std::endl;
	return (0);
}
