/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:44:05 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/27 15:44:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:
		AForm *	createShrubberyForm(const std::string & target) const;
		AForm *	createRobotomyForm(const std::string & target) const;
		AForm *	createPardonForm(const std::string & target) const;

	public:
		Intern( void );
		Intern( const Intern &oth);
		Intern& operator = ( const Intern &oth);
		~Intern( void );
		
		AForm *makeForm(std::string formname, std::string targetform);

		class	FormNotFound : public std::exception
		{
			public:
				const char *	what() const throw();
		};
};

#endif
