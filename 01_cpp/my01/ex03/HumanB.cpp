/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:42:21 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/28 17:38:18 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB( void )
{
}

void	HumanB::setWeapon( Weapon& weapon ) 
{
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) const
{
	if ( this->_weapon != NULL)
		std::cout << this->_name << " attacks with their "  << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " hasn't a weapon."  << std::endl;
}	

