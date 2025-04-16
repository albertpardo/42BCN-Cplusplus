/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:11:21 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 16:47:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& othAnimal );
		Animal& operator = ( const Animal& othAnimal );
		virtual ~Animal( void );

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
};

#endif
