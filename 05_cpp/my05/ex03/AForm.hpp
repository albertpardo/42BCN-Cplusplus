/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:08:39 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/16 14:36:19 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_issigned;
		const unsigned int	_gradesign;
		const unsigned int	_gradeexec;

	public:
		AForm( void );
		AForm( std::string name, unsigned int gradesign, unsigned int gradeexec);
		AForm( const AForm &oth );
		AForm& operator = ( const AForm &oth );
		virtual ~AForm( void );

		std::string		getName( void ) const;
		bool			getIsSigned( void ) const;
		unsigned int	getGradeToSign( void ) const;
		unsigned int	getGradeToExec( void ) const;

		void 			beSigned( Bureaucrat &bur );

		void			execute( Bureaucrat const & executor ) const;
		virtual void	executeForm( void ) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what( void ) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what( void ) const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what( void ) const throw();
		};
};

std::ostream & operator << (std::ostream &out, const AForm &form);

#endif
