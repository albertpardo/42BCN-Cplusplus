/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:35:58 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:36:07 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main( void )
{
	std::cout << " -> Create the Zombie One. <- " << std::endl;
	Zombie one = Zombie("One");
	one.announce();
	std::cout << "\n -> Create the Zombie with name Two using newZombie(). <-" << std::endl;
	Zombie*	two = newZombie("Two");
	two->announce();
	delete two;
	std::cout << "\n -> Create , print message and destroy the Zombie with name Random using randomChump(). <-" << std::endl;
	randomChump("Random");
	std::cout << "\n -> The main() has not more instructions. Expected : Debug message from Zombie with name One when he is deleted from the stack <-" << std::endl;
	return (0);
}
