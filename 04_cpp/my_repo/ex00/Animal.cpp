/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:02:44 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:25:49 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type("DefaultAnimal")
{
	std::cout << "Animal Default Constructor Called. _type = " << this->_type << std::endl;
}

Animal::Animal( std::string const type ) : _type(type)
{
	std::cout << "Animal Name Constructor Called. _type = " << this->_type << std::endl;
}

Animal::Animal( const Animal& othAnimal )
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = othAnimal;
}

Animal&	Animal::operator = ( const Animal& othAnimal )
{
	if (this != &othAnimal)
	{
		this->_type = othAnimal._type;
	}
	std::cout << "\tAnimal Copy assignament operator called. _type = " << this->_type << std::endl;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "Animal Default Destructor called. _type = " << this->_type << std::endl;
}
		
std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void		Animal::makeSound( void ) const
{
	std::cout << "Animal make sound : Sssshh!" << std::endl;
}
