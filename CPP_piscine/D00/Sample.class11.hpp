/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class11.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 07:54:17 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/21 08:43:25 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS11_HPP
# define SAMPLE_CLASS11_HPP

class Sample
{
	public:

		Sample( void );
		~Sample( void);

		static int	getNbInst ( void );

	private:

		static int		_nbInst;
};

#endif
