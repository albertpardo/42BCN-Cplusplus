/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class02.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:33:35 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/16 12:35:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class02.hpp"

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
