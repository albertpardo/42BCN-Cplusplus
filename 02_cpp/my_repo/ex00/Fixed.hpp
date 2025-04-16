/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:08:36 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/15 14:06:47 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
		
	public:
		Fixed( void );
		Fixed(const Fixed& fix);
		Fixed& operator = (const Fixed& fix); 
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif

