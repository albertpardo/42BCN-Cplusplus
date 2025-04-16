/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:16 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/17 14:45:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("DefaultName"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called : " << this->_name << std::endl;
}

ClapTrap::ClapTrap( std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called : " <<  this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& othTrap)
{
	std::cout << "ClapTrap copy constructor called" << this->_name << std::endl;
	*this = othTrap;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& othTrap)
{
	std::cout << "\tClapTrap Equal operator called. Info extracted from : " << othTrap._name << std::endl;
	if (this != &othTrap)
	{
		this->_name = othTrap._name;
		this->_hitPoints = othTrap._hitPoints;
		this->_energyPoints = othTrap._energyPoints;
		this->_attackDamage = othTrap._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called : " <<  this->_name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 1 )
		std::cout <<  "Can't attack. ClapTrap " << this->_name << " has no ENERGY POINTS." << std::endl;
	else if (this->_hitPoints < 1)
	{
		std::cout << "Can't attack. ClapTrap " << this->_name << " has no HIT POINTS.";
		std::cout << " (Actual Energy points = " << this->_energyPoints << ")" << std::endl;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!";
		std::cout << " (Actual Energy points = " << this->_energyPoints << ")" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
		std::cout << "Can't take Demage. ClapTrap " << this->_name << " has no HIT POINTS." << std::endl;
	else
	{
		if (this->_hitPoints >= amount)
		{
			this->_hitPoints -= amount;
			std::cout << "ClapTrap " << this->_name << " has been taken " << amount << " demage points from HIT POINTS! (Hit Points Remains : " << this->_hitPoints << ")" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->_name << " has been taken " << this->_hitPoints << " demage points from HIT POINTS and HIT POINTS are 0!" << std::endl;
			this->_hitPoints = 0;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1 )
		std::cout <<  "Can't be repaired. ClapTrap " << this->_name << " has no ENERGY POINTS." << std::endl;
	else if (this->_hitPoints < 1)
		std::cout << "Can't be repaired. ClapTrap " << this->_name << " has no HIT POINTS." << std::endl;
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " is being repared ";
		std::cout << ", getting " << amount << " hit points back!";
	  	std::cout << " (Total hit points = " << this->_hitPoints << ")";
		std::cout << " (Actual Energy points = " << this->_energyPoints << ")" << std::endl;
	}
}
