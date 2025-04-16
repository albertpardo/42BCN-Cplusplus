/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:42:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:43:06 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("DefaultWrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor Called. _type = " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& othWrongAnimal )
{
	std::cout << "\t- WrongAnimal Copy Constructor called" << std::endl;
	*this = othWrongAnimal;
}

WrongAnimal&	WrongAnimal::operator = ( const WrongAnimal& othWrongAnimal )
{
	std::cout << "\tWrongAnimal Copy assignament operator called" << std::endl;
	if (this != &othWrongAnimal)
	{
		this->_type = othWrongAnimal._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Default Destructor called. _type = "  << this->_type << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);	
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal make sound : Wrongsouuuuuuuund!" << std::endl;
}
