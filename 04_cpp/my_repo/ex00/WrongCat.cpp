/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:04:30 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 15:29:33 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	this->_type = "WrongCat";
	std::cout << "\t- WrongCat Default Constructor Called. _type = " << this->_type << std::endl;
}

WrongCat::WrongCat( const WrongCat& othWrongCat )
{
	std::cout << "\t- WrongCat Copy Constructor called" << std::endl;
	*this = othWrongCat;
}

WrongCat&	WrongCat::operator = ( const WrongCat& othWrongCat )
{
	std::cout << "\t\tWrongCat Copy assignament operator called" << std::endl;
	if (this != &othWrongCat)
	{
		this->_type = othWrongCat._type;
	}
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "\t- WrongCat Default Destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "\t- WrongCat make sound : Seeoooow!" << std::endl;
}
