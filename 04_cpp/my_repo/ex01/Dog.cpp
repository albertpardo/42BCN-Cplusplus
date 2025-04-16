/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:10:21 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:34:30 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	this->_type = "Dog";
	std::cout << "\t- Dog Default Constructor Called. _type = " <<this->_type << std::endl;                                     
	this->_brain = new Brain();
}

Dog::Dog( const Dog& othDog )
{
	std::cout << "\t- Dog Copy Constructor called" << std::endl;
	*this = othDog;
}

Dog& Dog::operator = ( const Dog& othDog )
{
	std::cout << "\t\tDog Copy assignament operator called" << std::endl;
	if (this != &othDog)
	{
		this->_type = othDog._type;
		this->_brain = new Brain(*othDog._brain);
	}
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "\t- Dog Default Destructor called" << std::endl;
	delete (this->_brain);
}

void	Dog::makeSound( void ) const
{
	std::cout << "\t- Dog make sound : Woof!  Woof!" << std::endl;
}
