/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class10.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:01:22 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/21 08:38:28 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS10_HPP
# define SAMPLE_CLASS10_HPP

class Sample
{
	public:

		Sample( int v );
		~Sample( void);
		
		int		getFoo ( void ) const;
		int		compare( Sample * other) const;

	private:

		int		_foo;
};

#endif
