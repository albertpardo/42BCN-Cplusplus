/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:43:47 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/16 14:36:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target);  // puede ser & target 
		PresidentialPardonForm( const PresidentialPardonForm &oth );
		PresidentialPardonForm& operator = (const PresidentialPardonForm &oth);
		~PresidentialPardonForm( void );
			
		void	executeForm( void ) const;
};

#endif
