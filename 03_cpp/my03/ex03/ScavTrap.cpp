/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:47:53 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/17 17:25:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
 	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\t- ScavTrap default constructor called : " << this->_name << std::endl;
}

ScavTrap::ScavTrap( std::string name)
{
	this->_name = name;
 	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\t- ScavTrap constructor called : " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& othTrap)
{
	std::cout << "\t- ScavTrap copy constructor called : " << this->_name << std::endl;
	*this = othTrap;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& othTrap)
{
	std::cout << "\t- ScavTrap Equal operator called. Info extracted from : " << othTrap._name << std::endl;
	if (this != &othTrap)
	{
		this->_name = othTrap._name;
		this->_hitPoints = othTrap._hitPoints;
		this->_energyPoints = othTrap._energyPoints;
		this->_attackDamage = othTrap._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "\t- ScavTrap destructor called : " <<  this->_name << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	if (this->_energyPoints < 1 )
		std::cout <<  "\t- Can't attack. ScavTrap " << this->_name << " has no ENERGY POINTS." << std::endl;
	else if (this->_hitPoints < 1)
		std::cout << "\t- Can't attack. ScavTrap " << this->_name << " has no HIT POINTS." << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "\t- ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!";
		std::cout << " (Actual Energy points = " << this->_energyPoints << ")" << std::endl;
	}
}

void	ScavTrap::guardGate()
{	if(this->_hitPoints < 1)
		std::cout << "\t- ScavTrap have 0 HIT POITS" << std::endl;
	else
		std::cout << "\t- ScavTrap " << this->_name << " is in Gate keeper mode." << std::endl;
}
