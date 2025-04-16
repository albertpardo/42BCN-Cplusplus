/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:29:54 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/18 10:54:17 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define	FORM_DEF_NAME "AFormDefaultName"
#define HIGHT_GRADE 1
#define LOW_GRADE 150

/*  --- Orthodox Canonical Form Functions (Public)--- */

AForm::AForm( void ) : \
	_name(FORM_DEF_NAME), _issigned(false), _gradesign(LOW_GRADE), _gradeexec(LOW_GRADE)
{
//	std::cout << "AForm default constuctod called." << std::endl;
}

AForm::AForm( std::string name, unsigned int gradesign, unsigned int gradexec) : \
	_name(name.empty() ? FORM_DEF_NAME : name), _issigned(false), _gradesign(gradesign), _gradeexec(gradexec)
{
//	std::cout << "AForm with data constructor called." << std::endl;
	if (gradesign < HIGHT_GRADE || gradexec < HIGHT_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradesign > LOW_GRADE || gradexec > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm( const AForm &oth) : \
	_name(oth.getName()), _gradesign(oth.getGradeToSign()), _gradeexec(oth.getGradeToExec())
{
//	std::cout << "AForm Copy constructor called." << std::endl;
	*this = oth;
}

AForm& AForm::operator = (const AForm &oth)
{
	if (this != &oth)
		this->_issigned = oth.getIsSigned();
	return (*this);
}

AForm::~AForm( void )
{
//	std::cout << "AForm destructor called. (" << this->_name << ", " << this->_issigned << ", " << this ->_gradesign << ", " << this-> _gradeexec << ")." << std::endl;
}

/* --- Other Public functions ---*/

std::string AForm::getName( void ) const
{
	return (this->_name);
}

bool AForm::getIsSigned( void ) const
{
	return (this->_issigned);
}

unsigned int AForm::getGradeToSign( void ) const
{
	return(this->_gradesign);
}

unsigned int AForm::getGradeToExec( void ) const
{
	return(this->_gradeexec);
}

void AForm::beSigned( Bureaucrat &bur )
{
	if (bur.getGrade() <= this->_gradesign)
		this->_issigned = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::	execute( Bureaucrat const & executor ) const
{
	if (this->getIsSigned() == true && executor.getGrade() <= this->getGradeToExec())
		this->executeForm();
	else if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else
		throw AForm::GradeTooHighException();
}

/* --- Exception functions ---*/

const char*	AForm::GradeTooHighException::what( void ) const throw()
{
	return ("AForm Grade is too high.");
}

const char*	AForm::GradeTooLowException::what( void ) const throw()
{
	return ("The grade is LOW than the Form Grade.");
}

const char* AForm::FormNotSignedException::what( void ) const throw()
{
	return ("Form is not signed");
}

/* --- Operators overwriting ---*/

std::ostream & operator << (std::ostream &out, const AForm &form)
{
	return (out << form.getName() << ", _issigned : " << form.getIsSigned() \
				<< ", _gradetosign: " << form.getGradeToSign() \
				<< ", _gradetoexec : " << form.getGradeToExec() \
				<< ").");	
}
