/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:39:52 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:39:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"


Zombie::Zombie( void )
{
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": DEBUG message when I was DELETED." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
