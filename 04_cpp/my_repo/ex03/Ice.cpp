/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:49:15 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 12:26:43 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"


Ice::Ice( void ) : AMateria::AMateria("ice")
{
//	std::cout << " - [Ice] : Default Constructor." << std::endl;
}

Ice::Ice( const Ice& other )
{
//	std::cout << " - [Ice] : Copy Constructor." << std::endl;
	*this = other;
}

Ice& Ice::operator=( const Ice& other )
{
//	std::cout << " - [Ice] : \t- Assignation operator." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;	
	}
	return (*this);
}

Ice::~Ice( void )
{
//	std::cout << " - [Ice] : Destructor." << std::endl;
}

Ice*	Ice::clone ( void ) const
{
	return (new Ice());
}	

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
