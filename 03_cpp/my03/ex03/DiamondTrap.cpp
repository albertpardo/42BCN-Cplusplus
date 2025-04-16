/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:49:16 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/17 17:40:09 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap::ClapTrap("DefaultName_clap_name")
{
	this->_name = "DefaultName";
	this->_hitPoints = 100; 
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "\t\t- DiamondTrap default constructor called : " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap( std::string name) : ClapTrap::ClapTrap( name + "_clap_name")
{
	std::cout << "\t\t- DiamondTrap constructor called : " << name << std::endl;
	this->_name = name;
	this->_hitPoints = 100; 
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& othTrap)
{
	std::cout << "\t\t- DiamondTrap copy constructor called" << std::endl;
	*this = othTrap;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& othTrap)
{
	std::cout << "\t\t\t- DiamondTrap Equal operator called. Info copied from : " << othTrap._name << std::endl;
	if (this != &othTrap)
	{
		ClapTrap::_name = othTrap._name + "_clap_name";
		this->_name = othTrap._name;
		this->_hitPoints = othTrap._hitPoints;
		this->_energyPoints = othTrap._energyPoints;
		this->_attackDamage = othTrap._attackDamage;

		std::cout << "\t\t\t - DiamondTrap::_name = " << this->_name << std::endl;
		std::cout << "\t\t\t - ClapTrap::_name = " << ClapTrap::_name << std::endl;
		std::cout << "\t\t\t - FragTrap::_name = " << FragTrap::_name << std::endl;
		std::cout << "\t\t\t - ScavTrap::_name = " << ScavTrap::_name << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "\t\t- DiamondTrap destructor called : " <<  this->_name << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "\n----- DiamondTrap::whoAmI() -----" << std::endl;
	std::cout << "DiamondTrap::_name = " << DiamondTrap::_name << std::endl;
	std::cout << "\tClapTrap::_name = " << ClapTrap::_name << std::endl;
	std::cout << "\tFragTrap::_name = " << FragTrap::_name << std::endl;
	std::cout << "\tScavTrap::_name = " << ScavTrap::_name << std::endl;
	std::cout << "-----------------------------------\n" << std::endl;
}
