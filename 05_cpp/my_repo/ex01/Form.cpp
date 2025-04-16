/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:29:54 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/27 12:30:53 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define	FORM_DEF_NAME "FormDefaultName"
#define HIGHT_GRADE 1
#define LOW_GRADE 150

/*  --- Orthodox Canonical Form Functions (Public)--- */

Form::Form( void ) : \
	_name(FORM_DEF_NAME), _issigned(false), _gradesign(LOW_GRADE), _gradeexec(LOW_GRADE)
{
	std::cout << "Form default constuctod called." << std::endl;
}

Form::Form( std::string name, unsigned int gradesign, unsigned int gradexec) : \
	_name(name.empty() ? FORM_DEF_NAME : name), _issigned(false), _gradesign(gradesign), _gradeexec(gradexec)
{
	std::cout << "Form with data constructor called." << std::endl;
	if (gradesign < HIGHT_GRADE || gradexec < HIGHT_GRADE)
		throw Form::GradeTooHighException();
	else if (gradesign > LOW_GRADE || gradexec > LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form( const Form &oth) : \
	_name(oth.getName()), _gradesign(oth.getGradeToSign()), _gradeexec(oth.getGradeToExec())
{
	std::cout << "Form Copy constructor called." << std::endl;
	*this = oth;
}

Form& Form::operator = (const Form &oth)
{
	if (this != &oth)
		this->_issigned = oth.getIsSigned();
	return (*this);
}

Form::~Form( void )
{
	std::cout << "Form destructor called. (" << this->_name << ", " << this->_issigned \
		<< ", " << this ->_gradesign << ", " << this-> _gradeexec << ")." << std::endl;
}

/* --- Other Public functions ---*/

std::string Form::getName( void ) const
{
	return (this->_name);
}

bool Form::getIsSigned( void ) const
{
	return (this->_issigned);
}

unsigned int Form::getGradeToSign( void ) const
{
	return(this->_gradesign);
}

unsigned	 int Form::getGradeToExec( void ) const
{
	return(this->_gradeexec);
}

void Form::beSigned( Bureaucrat &bur )
{
	if (bur.getGrade() <= this->_gradesign)
		this->_issigned = true;
	else
		throw Form::GradeTooLowException();
}

/* --- Exception functions ---*/

const char*	Form::GradeTooHighException::what( void ) const throw()
{
	return ("Form Grade is too high. Range [1,150]");
}

const char*	Form::GradeTooLowException::what( void ) const throw()
{
	return ("The grade is LOW than the Form Grade.");
}

/* --- Operators overwriting ---*/

std::ostream & operator << (std::ostream &out, const Form &form)
{
	return (out << form.getName() << " ( _issigned : " << form.getIsSigned() \
				<< ", _gradetosign: " << form.getGradeToSign() \
				<< ", _gradetoexec : " << form.getGradeToExec() \
				<< ").");	
}
