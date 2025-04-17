/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample1.class05.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:59:24 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/16 16:00:28 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample1.class05.hpp"

Sample1::Sample1( char p1, int p2, float p3)
{
	std::cout << "Constructor called" << std::endl;

	this->a1 = p1;
	std::cout << "this->a1 = " << this->a1 << std::endl;


	this->a2 = p2;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	
	this->a3 = p3;
	std::cout << "this->a3 = " << this->a3 << std::endl;

	return;
}

Sample1::~Sample1( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
