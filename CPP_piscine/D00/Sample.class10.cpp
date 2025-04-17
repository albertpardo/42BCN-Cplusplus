/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class10.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:52:19 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/20 16:00:04 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class10.hpp"

Sample::Sample( int v ) : _foo( v )
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int		Sample::getFoo( void ) const
{
	return (this->_foo);
}

int		Sample::compare( Sample * other ) const
{
	if ( this->_foo < other->getFoo() )
		return (-1);
	else if ( this->_foo > other->getFoo() )
		return (1);
	return (0);
}
