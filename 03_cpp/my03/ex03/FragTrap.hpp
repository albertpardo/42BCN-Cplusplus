/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:51:02 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/16 15:51:06 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#  include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap& othTrap );
		FragTrap& operator = ( const FragTrap& othTrap );
		~FragTrap( void );

		void highFivesGuys(void);
};

#endif
