/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:43:14 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/16 14:44:01 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#define G_SIGN 25
#define G_EXEC 5	
#define PRES_NAME "PresidentialPardonForm"

/*  --- Orthodox Canonical Form Functions (Public)--- */

PresidentialPardonForm::PresidentialPardonForm( void ) : \
	AForm::AForm(PRES_NAME, G_SIGN, G_EXEC), _target("DefaultTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm( std::string target) : \
	AForm::AForm(PRES_NAME, G_SIGN, G_EXEC), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &oth ) : \
	AForm::AForm(oth), _target(oth._target)
{
}

/* 
 * Call operator of base class:
 * https://stackoverflow.com/questions/4734846/calling-operators-of-base-class-safe
 */

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &oth)
{	
	AForm::operator=(oth);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

/* --- Other Public functions ---*/

void	PresidentialPardonForm::executeForm( void ) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
