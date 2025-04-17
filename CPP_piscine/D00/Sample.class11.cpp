/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class11.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:08:04 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/21 08:32:12 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class11.hpp"

Sample::Sample( void )
{
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst +=1;
	return;
}

Sample::~Sample( void )
{
	std::cout << "Destructor called" << std::endl;
	Sample::_nbInst -=1;
	return;
}

int		Sample::getNbInst( void )
{
	return (Sample::_nbInst);
}

int		Sample::_nbInst = 0;
