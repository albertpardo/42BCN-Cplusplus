/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:46:15 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:46:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character( void ) : _name("DefaultCharacterName")
{
	int	i;

//	std::cout << "[Character] : Default Constructor." << std::endl;
	i = -1;
	while(++i < SLOTS)
		this->_inventory[i] = NULL;
}

Character::Character( const std::string  name ) : _name(name)
{
	int	i;

//	std::cout << "[Character] : Constructor with _name = " << this->_name << std::endl;
	i = -1;
	while(++i < SLOTS)
		this->_inventory[i] = NULL;
}

Character::Character( const Character& other )
{
//	std::cout << "[Character] : Copy Constructor." << std::endl;
	*this = other;
}

Character& Character::operator=( const Character& other )
{
	int i;

//	std::cout << "[Character] : Assignation operator." << std::endl;
	if (this != &other)
	{
		i = -1;
		while (++i < SLOTS)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character( void )
{
	int	i;
	
//	std::cout << "[Character] : Destructor." << std::endl;
	i = -1;
	while(++i < SLOTS)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

std::string const &  Character::getName( void ) const
{
	return (this->_name);
}

void	Character::equip( AMateria* m )
{
	int i;

	if (m == NULL)
	{
		std::cout << "materia is null pointer. Learn is no possible." << std::endl;
		return;
	}
	i = -1;
	while (++i < SLOTS)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
		//	std::cout << "Materia = " << m->getType() << " on Slot " << i << std::endl;
			break;
		}
	}
	if (i == SLOTS)
		std::cout << "No available memory. No free slots." << std::endl;
}

void	Character::unequip( int idx )
{
	if (idx > -1 && idx < SLOTS)
	{
		if (this->_inventory[idx] != NULL)
		{
			this->_inventory[idx] = NULL;
			std::cout << this->_name << "'s inventory[" << idx << "] has been unequiped" << std::endl;
		}
		else
			std::cout << "The inventory is empty in the idx = " << idx << std::endl;
	}
	else
		std::cout << "idx = " << idx << " out of SLOTS range . idx valid range from 0 to " << SLOTS << std::endl;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx > -1 && idx < SLOTS && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	else
		std::cout << "idx = " << idx << " out of SLOTS range . idx valid range from 0 to " << SLOTS << std::endl;
}

AMateria *	Character::getMateria( int idx ) {

	if (idx >= 0 && idx < SLOTS)
		return (this->_inventory[idx]);
	else
		return (NULL);
}

void	Character::showInventory( void ) const
{
	int i;

	std::cout << "\n---- INVENTORY ----" << std::endl;
	i = -1;
	while (++i < SLOTS)
	{
		if (this->_inventory[i] != NULL)
			std::cout << "i = " << i << " -> (" << this->_inventory[i] << "), " << this->_inventory[i]->getType()<< std::endl;
		else
			std::cout << "i = " << i << " -> NULL" << std::endl;
	}
}
