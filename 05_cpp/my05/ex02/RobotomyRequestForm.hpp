/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:43:52 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/17 07:54:07 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp" 

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target);  // puede ser & target
		RobotomyRequestForm( const RobotomyRequestForm &oth );
		RobotomyRequestForm& operator = ( const RobotomyRequestForm &oth );
		~RobotomyRequestForm( void );
		
		void	executeForm( void ) const;
};

#endif

