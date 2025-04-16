/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:43:20 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/28 17:37:10 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon*		_weapon;
		std::string	_name;

	public:
		HumanB( std::string name );
		~HumanB( void );
		void		setWeapon( Weapon& weapon );
		void		attack( void ) const;
};

#endif
