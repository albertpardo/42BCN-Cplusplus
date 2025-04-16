/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:29 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 17:06:32 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class	AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal( void );
		AAnimal( std::string type );
		AAnimal( const AAnimal& othAAnimal );
		AAnimal& operator = ( const AAnimal& othAAnimal );
		virtual ~AAnimal( void );

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;
};

#endif
