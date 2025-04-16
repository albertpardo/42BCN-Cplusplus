/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:40:01 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:40:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

#define HORDE_SIZE 8
#define DEFAULT_NAME "DefaultName"

int	main( void )
{
	int	i;
	Zombie* horde;

	horde = zombieHorde( HORDE_SIZE, DEFAULT_NAME);
	i = -1;
	while (++i < HORDE_SIZE)
	{
		std::cout << "-Zombie " << i << "/" << HORDE_SIZE << " says-" << std::endl;
		horde[i].announce();
	}
	std::cout << std::endl;
	delete [] horde;
	return (0);
}
