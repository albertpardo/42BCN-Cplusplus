/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:04:10 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/16 14:31:49 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, unsigned grade );
		Bureaucrat( const Bureaucrat &oth );
		Bureaucrat& operator = ( const Bureaucrat &oth );
		~Bureaucrat( void );

		std::string		getName( void ) const;
		unsigned int	getGrade( void ) const;
		void			incrementGrade( void );
		void			decrementGrade( void );

		void 			signForm( AForm &form );

		void			executeForm( AForm const & form ) const;

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

std::ostream & operator << (std::ostream &out, const Bureaucrat &bureau);

#endif
