/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class03.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:33:35 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/16 14:00:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class03.hpp"

Sample::Sample( void )
{
	std::cout << "Constructor called" << std::endl;
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
