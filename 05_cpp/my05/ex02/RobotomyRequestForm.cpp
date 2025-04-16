/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:43:23 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/17 09:00:01 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#define G_SIGN 72
#define G_EXEC 45
#define ROBO_NAME "RobotomyRequestForm"

/*  --- Orthodox Canonical Form Functions (Public)--- */

RobotomyRequestForm::RobotomyRequestForm( void ) : \
	AForm::AForm(ROBO_NAME, G_SIGN, G_EXEC), _target("DefaultTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm( std::string target) : \
	AForm::AForm(ROBO_NAME, G_SIGN, G_EXEC), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &oth) : \
	AForm::AForm(oth), _target(oth._target)
{
}

/* 
 * Call operator of base class:
 * https://stackoverflow.com/questions/4734846/calling-operators-of-base-class-safe
 */

RobotomyRequestForm& RobotomyRequestForm::operator = ( const RobotomyRequestForm &oth )
{
	AForm::operator=(oth);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

/* --- Other Public functions ---*/

void	RobotomyRequestForm::executeForm( void ) const
{
	static bool	isrobo = true;
	std::cout << "Rrrrrrrrrr ...." << std::endl;
	if (isrobo)
	{
		isrobo = false;
		std::cout << this->_target << " has been robotomized succesfully" << std::endl;
	}
	else
	{
		isrobo = true;
		std::cout << "Robotomy failed on " << this->_target << std::endl;
	}
}
