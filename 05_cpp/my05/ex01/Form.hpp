/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:08:39 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/16 09:51:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_issigned;
		const unsigned int	_gradesign;
		const unsigned int	_gradeexec;

	public:
		Form( void );
		Form( std::string name, unsigned int gradesign, unsigned int gradeexec);
		Form( const Form &oth );
		Form& operator = ( const Form &oth );
		~Form( void );

		std::string		getName( void ) const;
		bool			getIsSigned( void ) const;
		unsigned int	getGradeToSign( void ) const;
		unsigned int	getGradeToExec( void ) const;

		void 			beSigned( Bureaucrat &bur );

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
};

std::ostream & operator << (std::ostream &out, const Form &form);

#endif
