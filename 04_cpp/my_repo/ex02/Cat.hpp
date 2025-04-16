/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:54 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 17:06:57 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
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
