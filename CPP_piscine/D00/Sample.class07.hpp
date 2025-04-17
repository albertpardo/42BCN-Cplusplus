/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class07.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:38:28 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/20 14:22:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS07_HPP
# define SAMPLE_CLASS07_HPP

class Sample
{
	public:

		int		publicFoo;

		Sample( void );
		~Sample( void );

		void	publicBar( void ) const;
	
	private :

		int		_privateFoo;

		void	_privateBar( void ) const;
};

#endif
