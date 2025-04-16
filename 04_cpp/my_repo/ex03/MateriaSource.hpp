/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:33:33 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 11:33:35 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define SLOTS 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materias[SLOTS];
		
	public:
		MateriaSource( void );                                      
		MateriaSource( const MateriaSource& other );
		MateriaSource& operator=( const MateriaSource& other );
		~MateriaSource( void );

		void 		learnMateria( AMateria* materia );
		AMateria*	createMateria( std::string const & type );
};
#endif
