/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:33:10 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 12:04:00 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class	AMateria;

class	ICharacter
{
	public:
		virtual 			~ICharacter( void ) {};

		virtual std::string const & getName( void ) const = 0;
		virtual void 		equip( AMateria* m ) = 0;
		virtual void 		unequip( int idx ) = 0;
		virtual void 		use( int idx, ICharacter& target ) = 0;
};

#endif
