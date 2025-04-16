/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:47:40 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/17 17:22:41 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\t- FragTrap default constructor called : " << this->_name << std::endl;
}

FragTrap::FragTrap( std::string name )
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\t- FragTrap constructor called : " <<  name << std::endl;
}

FragTrap::FragTrap(const FragTrap& othTrap)
{
	std::cout << "\t- FragTrap copy constructor called : " << this->_name << std::endl;
	*this = othTrap;
}

FragTrap& FragTrap::operator = (const FragTrap& othTrap)
{
	std::cout << "\t\t- FragTrap Equal operator called. Info extracted from : " << othTrap._name << std::endl;
	if (this != &othTrap)
	{
		this->_name = othTrap._name;
		this->_hitPoints = othTrap._hitPoints;
		this->_energyPoints = othTrap._energyPoints;
		this->_attackDamage = othTrap._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "\t- FragTrap destructor called : " <<  this->_name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints < 1)
		std::cout << "\t- FragTrap has 0 HITPOINT for highFives by " << this->_name << std::endl;
	else
		std::cout << "\t- FragTrap highFivesGuys! by " <<  this->_name << std::endl;
}
