/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:05:58 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 14:06:01 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& othWrongAnimal );
		WrongAnimal& operator = ( const WrongAnimal& othWrongAnimal );
		~WrongAnimal( void );

		std::string	getType( void ) const;
		void		makeSound( void ) const;
};

#endif
