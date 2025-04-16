/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:12:13 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/15 14:57:51 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/*
 * Fixed& is used for pre operators
 * Fixed  is used for post operators
 */

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
		
	public:
		Fixed( void );
		Fixed( const int numInt );
		Fixed( const float numFloat );
		Fixed( const Fixed& fix );
		Fixed&	operator = ( const Fixed& fix );
		~Fixed( void );

		bool	operator > ( const Fixed& fix ) const; 
		bool	operator < ( const Fixed& fix ) const; 
		bool	operator >= ( const Fixed& fix ) const; 
		bool	operator <= ( const Fixed& fix ) const; 
		bool  	operator == ( const Fixed& fix ) const; 
		bool	operator != ( const Fixed& fix ) const; 

		Fixed	operator + ( const Fixed& fix ); 
		Fixed	operator - ( const Fixed& fix ); 
		Fixed	operator * ( const Fixed& fix ); 
		Fixed	operator / ( const Fixed& fix ); 

		Fixed&	operator ++ ( void );	 
		Fixed&	operator -- ( void ); 
		Fixed	operator ++ ( int ); 
		Fixed	operator -- ( int ); 

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed&		min( Fixed &fix1, Fixed &fix2);
		static Fixed&		max( Fixed &fix1, Fixed &fix2);
		static const Fixed&	min( const Fixed &fix1, const Fixed &fix2);
		static const Fixed& max( const Fixed &fix1, const Fixed &fix2);
};
		
std::ostream	&operator << (std::ostream &out, const Fixed &nb);

#endif
