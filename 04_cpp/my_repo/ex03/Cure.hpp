/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:33:03 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 11:33:06 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( Cure const & other );
		Cure &	operator=( Cure const & other );
		~Cure( void );
		
		Cure* 	clone ( void ) const;
		void	use(ICharacter& target);
};

#endif
