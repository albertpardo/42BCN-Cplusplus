/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:42:56 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:42:58 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon&		_weapon;
		std::string	_name;

	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );
		void	attack( void ) const;
};

#endif
