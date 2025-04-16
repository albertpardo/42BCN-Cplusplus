/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:32:54 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 11:32:56 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define SLOTS 4

class Character : public ICharacter
{	
	private:
		AMateria* 	_inventory[SLOTS];
		std::string	_name;

	public:
		Character( void ); 
		Character( const std::string name);
		Character( const Character& other);
		Character& operator=(const Character& other);
		~Character( void );		
		
		std::string const & getName( void ) const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

		AMateria*			getMateria( int idx);
		void				showInventory( void ) const;
};

#endif
