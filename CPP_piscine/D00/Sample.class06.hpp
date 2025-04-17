/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class06.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:48:13 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/17 09:17:41 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS06_HPP
# define SAMPLE_CLASS06_HPP

class Sample
{
	public:

		float const	pi;
		int			qd;

		Sample( float const f );
		~Sample( void );

		void	bar( void ) const;
};

#endif
