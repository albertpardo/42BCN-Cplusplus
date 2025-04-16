/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:49:44 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/17 17:27:05 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap defaultName;
	DiamondTrap unoDiamond("UNODiamond");
	DiamondTrap dosDiamond("DOSDiamond");
	DiamondTrap dosDiamondREF(dosDiamond);
	DiamondTrap	tresDiamond;
	int i;
	
	std::cout << "\n --- START->  'UNODiamond' attacks 'Other' ---" << std::endl;
	i = -1;
	while (++i < 9)
		unoDiamond.attack("Other");
	std::cout << " --- END -> 'UNODiamond' attacks 'Other' ---\n" << std::endl;

	unoDiamond.beRepaired(40);
	unoDiamond.highFivesGuys();
	
	std::cout << "\n --- START->  'UNODiamond' takeDamage ---" << std::endl;
	i = -1;
	while (++i < 5)
		unoDiamond.takeDamage(35);
	std::cout << " --- END -> 'UNODiamond' takeDamage ---\n" << std::endl;
	
	unoDiamond.beRepaired(40);
	unoDiamond.highFivesGuys();
	
	unoDiamond.whoAmI();

	std::cout << "============================" << std::endl;
	std::cout << "--- tresDiamond = unoDiamond" << std::endl;
	tresDiamond = unoDiamond;
	tresDiamond.whoAmI();
	std::cout << "============================\n" << std::endl;

	return (0);
}
