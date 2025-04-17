/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class09.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:38:28 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/20 15:11:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS09_HPP
# define SAMPLE_CLASS09_HPP

class Sample
{
	public:

		Sample( void );
		~Sample( void );

		int		getFoo( void ) const;
		void	setFoo( int v);

	
	private :

		int		_foo;
};

#endif
