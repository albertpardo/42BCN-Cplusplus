/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class09.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:52:19 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/20 16:02:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class09.hpp"

Sample::Sample( void )
{
	std::cout << "Constructor called" << std::endl;

	this->setFoo(0);
	std::cout << "this->getFoo: " << this->getFoo() << std::endl;

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

void	Sample::setFoo( int v )
{
	if (v >= 0)
		this->_foo = v;
	return;
}
