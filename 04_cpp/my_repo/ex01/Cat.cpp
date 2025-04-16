/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:10:13 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:33:32 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	this->_type = "Cat";
	std::cout << "\t- Cat Default Constructor Called._type = " << this->_type << std::endl;
	this->_brain = new Brain();
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
	{
		Animal::_type = othCat.Animal::_type;
		this->_brain = new Brain(*othCat._brain);
	}
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "\t- Cat Default Destructor called" << std::endl;
	delete (this->_brain);
}

void	Cat::makeSound( void ) const
{
	std::cout << "\t- Cat make sound : Meeoooow!" << std::endl;
}
