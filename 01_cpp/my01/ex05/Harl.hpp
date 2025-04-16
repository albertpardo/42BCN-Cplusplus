/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:46:55 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:47:10 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );

	public:
		Harl();
		~Harl();
		void  complain( std::string level );
};

#endif
