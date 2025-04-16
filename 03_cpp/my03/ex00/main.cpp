/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/16 15:45:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap defaultName;
	ClapTrap uno("UNO");
	ClapTrap dos("DOS");
	ClapTrap dosREF(dos);

	int i;
	
	std::cout << "\n --- START->  'UNO' attacks 'Other' ---" << std::endl;

	i = -1;
	while (++i < 9)
		uno.attack("Other");
	std::cout << " --- END -> 'UNO' attacks 'Other' ---\n" << std::endl;

	uno.beRepaired(40);
	std::cout << std::endl;
	uno.attack("Dos");

	std::cout << "\n --- START->  'UNO' takeDamage ---" << std::endl;
	i = -1;
	while (++i < 6)
		uno.takeDamage(10);
	std::cout << " --- END -> 'UNO' takeDamage ---\n" << std::endl;

	return (0);
}
