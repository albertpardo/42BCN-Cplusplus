/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:39:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 16:59:49 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain( void )
{
	int	i;

	std::cout << "\t\t- Brain Default Constructor called," << std::endl;
	i = -1;
	while (++i < MAX_IDEAS)
		this->_ideas[i] = "";
}

Brain::Brain(Brain& other)
{
	std::cout << "\t- Brain Copy Constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator = ( const Brain& other )
{
	int	i;

	i = -1;
	if (this != &other)
	{
		while (++i < MAX_IDEAS)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "\t- Brain Default Destructor called," << std::endl;
}
