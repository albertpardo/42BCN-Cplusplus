/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:37:07 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 17:32:21 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type("DefaultAAnimal")
{
	std::cout << "AAnimal Default Constructor Called. _type = " << this->_type << std::endl;
}

AAnimal::AAnimal( std::string const type ) : _type(type)
{
	std::cout << "AAnimal Name Constructor Called. _type = " << this->_type << std::endl;
}
		
AAnimal::AAnimal( const AAnimal& othAAnimal )
{
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	*this = othAAnimal;
}

AAnimal&	AAnimal::operator = ( const AAnimal& othAAnimal )
{
	if (this != &othAAnimal)
	{
		this->_type = othAAnimal._type;
	}
	std::cout << "\tAAnimal Copy assignament operator called. _type = " << this->_type << std::endl;
	return (*this);
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal Default Destructor called. _type = " << this->_type << std::endl;
}

std::string	AAnimal::getType( void ) const
{
	return (this->_type);
}

/*
void	AAnimal::makeSound( void ) const
{
	std::cout << "AAnimal make sound : Sssshh!" << std::endl;
}
*/
