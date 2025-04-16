/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:42:30 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:42:33 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type)
{
	Weapon::setType(type);
}

Weapon::~Weapon()
{
}


const std::string& Weapon::getType( void ) const
{
	const std::string&	type = _type;
	return(type);
}

void Weapon::setType( std::string type )
{
	this->_type = type;
}
