/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:43:08 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/27 19:14:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define MAX_NUM_FORM 3
/* --- Private Functions --- */

AForm *	Intern::createShrubberyForm(const std::string & target) const
{
	return (new ShrubberyCreationForm(target));
}
AForm *	Intern::createRobotomyForm(const std::string & target) const
{
	return (new RobotomyRequestForm(target));
}
AForm *	Intern::createPardonForm(const std::string & target) const
{
	return (new PresidentialPardonForm(target));
}

/*  --- Orthodox Canonical Form Functions (Public)--- */

Intern::Intern( void ) {}

Intern::Intern( const Intern &oth)
{
	*this = oth;
}

Intern& Intern::operator = ( const Intern &oth)
{
	if (this != &oth)
		return (*this);
	return (*this);
}

Intern::~Intern( void ) {}

/* --- Other Public functions ---*/

/*
 * Array of functions pointers
 * https://textbooks.cs.ksu.edu/cis308/7-chapter/7_3-arraysfnptrs/
 *
 * Concept also done in CPP01
 */

AForm *	Intern::makeForm(std::string formname, std::string targetform)
{
	int		i = -1;
	AForm	*newForm = NULL;
	std::string	formNames[MAX_NUM_FORM] = 
	{
		"presidential",
		"frobotomy",
		"shruberry"
	};
	AForm *	(Intern::*createForm[MAX_NUM_FORM])(const std::string &) const = 
	{
		&Intern::createPardonForm,
		&Intern::createRobotomyForm,
		&Intern::createShrubberyForm
	};
	
	while (++i < MAX_NUM_FORM)
	{
		if (formname == formNames[i])
		{	
			newForm = (this->*createForm[i])(targetform);
			std::cout << "Intern creates " << newForm->getName() << std::endl;
			return (newForm);
		}
	}
	std::cout << "Intern couldn't find " << formname << " form." << std::endl;
	throw Intern::FormNotFound();
	return (NULL);
}

/* --- Exception functions ---*/

const char *	Intern::FormNotFound::what(void) const throw()
{
	return ("Form Name is not in the Intern's forms list");
}
