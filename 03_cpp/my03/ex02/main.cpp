/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:48:03 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/16 15:48:09 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	FragTrap defaultName;
	FragTrap unoFrag("UNOFrag");
	FragTrap dosFrag("DOSFrag");
	FragTrap dosFragREF(dosFrag);
	ScavTrap tresScav("tresScav");

	int i;
	
	std::cout << "\n --- START->  'UNOFrag' attacks 'Other' ---" << std::endl;
	i = -1;
	while (++i < 9)
		unoFrag.attack("Other");
	std::cout << " --- END -> 'UNOFrag' attacks 'Other' ---\n" << std::endl;

	unoFrag.beRepaired(10);
	unoFrag.highFivesGuys();
	
	std::cout << "\n --- START->  'UNOFrag' takeDamage ---" << std::endl;
	i = -1;
	while (++i < 5)
		unoFrag.takeDamage(20);
	std::cout << " --- END -> 'UNOFrag' takeDamage ---\n" << std::endl;
	
	unoFrag.beRepaired(40);

	std::cout << "\n--- START-> 'UNOFrag' hi5 ---" << std::endl;
	unoFrag.highFivesGuys();
	unoFrag.takeDamage(50);
	unoFrag.highFivesGuys();
	std::cout << "--- END-> 'UNOFrag' hi5 ---" << std::endl;

	std::cout << "\n--- 'tresScav' guardgate ---" << std::endl;
	tresScav.guardGate();
	std::cout << std::endl;

	return (0);
}
