/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:10:31 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/28 14:40:59 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class ScalarConverter
{
	private:
		enum _varTypes
		{
			_NO_TYPE,
			_T_CHAR,
			_T_INT,
			_T_FLOAT,
			_T_DOUBLE	
		};

		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &oth);
		ScalarConverter& operator = ( const ScalarConverter &oth);
		~ScalarConverter( void );

		static int	_getScalarType( const std::string &str );
		static bool	_isChar( const std::string &str );
		static bool	_isInt( const std::string &str );
		static bool	_isFloat( const std::string &str );
		static bool	_isDouble( const std::string &str );
		static void	_putChar( const std::string &str, int type );
		static void	_putInt( const std::string &str, int type );
		static void	_putFloat( const std::string &str, int type );
		static void	_putDouble( const std::string &str, int type );

	public:
		static void	convert( const std::string &str);
};
#endif
