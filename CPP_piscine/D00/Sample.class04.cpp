/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class04.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:33:35 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/16 14:46:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class04.hpp"

Sample::Sample( void )
{
	std::cout << "Construct or called" << std::endl;

	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;

	this->bar();

	return;
}

Sample::~Sample( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::bar( void )
{
	std::cout << "Member function bar called" << std::endl;
	return;
}
