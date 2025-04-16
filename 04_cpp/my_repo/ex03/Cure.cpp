/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:47:19 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 12:26:27 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure( void ) : AMateria::AMateria("cure")
{
//	std::cout << " - [Cure] : Default Constructor." << std::endl;
}

Cure::Cure( const Cure& other )
{
//	std::cout << " - [Cure] : Copy Constructor." << std::endl;
	*this = other;
}

Cure& Cure::operator=( const Cure& other )
{
//	std::cout << " - [Cure] : \t- Assignation operator." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;	
	}
	return (*this);
}

Cure::~Cure( void )
{
//	std::cout << " - [Cure] : Destructor." << std::endl;
}

Cure*	Cure::clone ( void ) const
{
	return (new Cure());
}	

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
