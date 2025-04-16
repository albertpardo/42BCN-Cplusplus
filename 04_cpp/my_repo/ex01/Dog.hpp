/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:11:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 14:11:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain* _brain;
		
	public:
		Dog( void );
		Dog( const Dog& othDog );
		Dog& operator = ( const Dog& othDog );
		~Dog( void );

		void	makeSound( void ) const;
};

#endif
