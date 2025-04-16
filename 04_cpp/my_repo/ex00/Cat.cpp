/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:03:13 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:27:07 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	this->_type = "Cat";
	std::cout << "\t- Cat Default Constructor Called._type = " << this->_type << std::endl;
}

Cat::Cat( const Cat& othCat ) : Animal("Cat")
{
	std::cout << "\t- Cat Copy Constructor called" << std::endl;
	*this = othCat;
}

Cat&	Cat::operator = ( const Cat& othCat )
{
	std::cout << "\t\tCat Copy assignament operator called" << std::endl;
	if (this != &othCat)
		Animal::_type = othCat.Animal::_type;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "\t- Cat Default Destructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "\t- Cat make sound : Meeoooow!" << std::endl;
}
