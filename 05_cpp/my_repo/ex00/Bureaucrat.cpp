/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:40 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/16 09:32:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

#define	DEFAULT_NAME "DefaultName"
#define HIGHT_GRADE 1
#define LOW_GRADE 150

/*  --- Orthodox Canonical Form Functions (Public)--- */

Bureaucrat::Bureaucrat( void ) : _name(DEFAULT_NAME), _grade(LOW_GRADE)
{
	std::cout << "Bureaucrat Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, unsigned int grade ) : _name(name.empty() ? DEFAULT_NAME : name)
{
	std::cout << "Bureaucrat(name, grade) constructor called." << std::endl;
	if (grade >= HIGHT_GRADE && grade <= LOW_GRADE)
		this->_grade = grade;
	else if (grade < HIGHT_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : _name(oth.getName())
{
	std::cout << "Bureaucrat Copy constructor called." << std::endl;
	*this = oth;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &oth)
{
	if (this != &oth)
		this->_grade = oth.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat Destructor called.(" << this->_name << "," << this->_grade << ")." << std::endl;
}

/* --- Other Public functions ---*/

std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade > HIGHT_GRADE)
	   	this->_grade--;	
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade < LOW_GRADE)
	   	this->_grade++;	
	else
		throw Bureaucrat::GradeTooLowException();
}

/* --- Exception functions ---*/

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too high. Range [1,150]");
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low. Range [1,150]");
}

/* --- Operators overwriting ---*/

std::ostream & operator << (std::ostream &out, const Bureaucrat &bureau)
{
	return (out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".");	
}
