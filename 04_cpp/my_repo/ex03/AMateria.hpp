/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:32:40 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 12:04:09 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( AMateria const & other);
		AMateria&	operator=( AMateria const & other );
		virtual ~AMateria( void );

		std::string const & getType() const;
		virtual			AMateria* clone( void ) const = 0;
		virtual void	use( ICharacter& target );
};

#endif
