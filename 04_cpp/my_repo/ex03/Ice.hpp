/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:33:21 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 11:33:23 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( Ice const & other );
		Ice &	operator=( Ice const & other );
		~Ice( void );
		
		Ice*	clone ( void ) const;
		void	use(ICharacter& target);
};

#endif
