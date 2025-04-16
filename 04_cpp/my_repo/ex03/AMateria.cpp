/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:45:47 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 12:07:57 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("noMateria")
{
//	std::cout << "[AMateria] : Default Constructor." << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
//	std::cout << "[AMateria] : Constructor with _type = " << this->_type << std::endl;
}

AMateria::AMateria( const AMateria& other )
{
//	std::cout << "[AMateria] : Copy Constructor." << std::endl;
	*this = other;
}

AMateria& AMateria::operator=( const AMateria& other )
{
//	std::cout << "[AMateria] : Assignation operator." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;	
	}
	return (*this);
}

AMateria::~AMateria( void )
{
//	std::cout << "[AMateria] : Destructor." << std::endl;
}

std::string const &  AMateria::getType() const
{
	return (this->_type);
}

void   AMateria::use( ICharacter& target )
{
	std::cout << "* [AMateria] use message for " << target.getName() << std::endl;
}
