/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:11:37 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 14:11:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain* _brain;
		
	public:
		Cat( void );
		Cat( const Cat& othCat );
		Cat& operator = ( const Cat& othCat );
		~Cat( void );

		void	makeSound( void ) const;
};

#endif
