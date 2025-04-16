/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:03:27 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:28:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	this->_type = "Dog";
	std::cout << "\t- Dog Default Constructor Called. _type = " << this->_type << std::endl;      
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
		this->_type = othDog._type;
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "\t- Dog Default Destructor called" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "\t- Dog make sound : Woof!  Woof!" << std::endl;
}
