/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:49:37 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:49:42 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	int	i;

//	std::cout << "[MateriaSource] : Default Constructor." << std::endl;

	i = -1;
	while(++i < SLOTS)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
//	std::cout << "[MateriaSource] : Copy Constructor." << std::endl;
	*this = other;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other )
{	
	int	i;

//	std::cout << "[MateriaSource] : \t- Assignation operator." << std::endl;
	if (this != &other)
	{
		i = -1;
		while (++i < SLOTS)
		{
			if (this->_materias[i] != NULL)
				delete this->_materias[i];
			if (other._materias[i] != NULL)
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	int	i;
	
//	std::cout << "[MateriaSource] : Destructor." << std::endl;
	i = -1;
	while(++i < SLOTS)
	{
		if (this->_materias[i] != NULL)
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}
		
void	MateriaSource::learnMateria( AMateria* materia )
{
	int i;

	if (materia == NULL)
	{
		std::cout << "materia is null pointer. Learn is no possible." << std::endl;
		return;
	}
	i = -1;
	while (++i < SLOTS)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = materia;
//			std::cout << "Materia = " << materia->getType() << " on Slot " << i << std::endl;
			break;
		}
	}
	if (i == SLOTS)
		std::cout << "No available memory. No free slots." << std::endl;
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	int i;

	i = -1;
	while(++i < SLOTS)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	std::cout << "Materia type = " << type << " not found." << std::endl;
	return (NULL);
}
