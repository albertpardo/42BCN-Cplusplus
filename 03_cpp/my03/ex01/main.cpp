/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:27 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/16 15:46:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap defaultNameScav;
	ScavTrap unoScav("unoScav");
	ScavTrap dosScav("dosScav");
	ScavTrap dosScavREF(dosScav);

	int i;
	
	std::cout << "\n --- START->  'unoScav' attacks 'Other' ---" << std::endl;
	i = -1;
	while (++i < 9)
		unoScav.attack("Other");
	std::cout << " --- END -> 'unoScav' attacks 'Other' ---\n" << std::endl;

	unoScav.beRepaired(40);
	
	std::cout << "\n --- START->  'unoScav' takeDamage ---" << std::endl;
	i = -1;
	while (++i < 6)
		unoScav.takeDamage(40);
	std::cout << " --- END -> 'unoScav' takeDamage ---\n" << std::endl;

	return (0);
}
