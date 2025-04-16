/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:43:58 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/17 08:51:37 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target);  // puede ser & target
		ShrubberyCreationForm( const ShrubberyCreationForm &oth);
		ShrubberyCreationForm& operator = ( const ShrubberyCreationForm &oth);
		~ShrubberyCreationForm( void );
		
		void	executeForm( void ) const;
};

#endif
