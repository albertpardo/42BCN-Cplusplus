/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:35:46 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:35:49 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{

	this->_name = name;
	std::cout << this->_name << ": This is my DEBUG message when I was CREATED." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "\n" << this->_name << ": DEBUG message when I was DELETED." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
