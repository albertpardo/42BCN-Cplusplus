/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:35:22 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/04 09:51:05 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib> 
#include <iostream>
#include <limits>
#include "ScalarConverter.hpp"

#define IMPOSSIBLE "impossible"
#define NON_DISPLAY "Non displayable"


/*  --- Orthodox Canonical Form Functions (Private)--- */
ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter & oth)
{
	*this = oth;
}

ScalarConverter & ScalarConverter::operator=( const ScalarConverter & oth)
{
	(void) oth;
	return (*this);
}

ScalarConverter::~ScalarConverter( void ) {}

/* ------------------- PRIVATE MEMBER FUNCTIONS ------------------*/

/*
 *	Detect typo : CHAR, INT , float, double
 */

int	ScalarConverter::_getScalarType( const std::string &str )
{
	if (ScalarConverter::_isChar(str))
		return (ScalarConverter::_T_CHAR);
	if (ScalarConverter::_isInt(str))
		return (ScalarConverter::_T_INT);
	if (ScalarConverter::_isFloat(str))
		return (ScalarConverter::_T_FLOAT);
	if (ScalarConverter::_isDouble(str))
		return (ScalarConverter::_T_DOUBLE);
	return (ScalarConverter::_NO_TYPE);
}

/*
 * <cctype> : std::isprint, std::isdigit
 */

bool	ScalarConverter::_isChar( const std::string &str )
{
	if (str.length() == 1 && std::isprint(str.at(0)) && !std::isdigit(str.at(0)))
		return (true);	
	return (false);
}

/*
 * <cstdlib> : std::strtol  
 * <limits>  : std::numeric_limits<int>
 */

bool	ScalarConverter::_isInt( const std::string &str )
{
	const char	*stmp;
	char		*endptr;
	long		num;

	stmp = str.c_str();
	num = std::strtol(stmp, &endptr, 10);
	if (endptr != str && *endptr == '\0' && \
			num <= std::numeric_limits<int>::max() && \
			num >= std::numeric_limits<int>::min())
		return (true);	
	return (false);
}

/*
 * <cmath>   : std::abs
 * <cstring> : std::strlen
 * <cstdlib> : std::strtod  
 * <limits>  : std::numeric_limits<float>
 * <string>	 : find , std::string::npos
 */

bool	ScalarConverter::_isFloat( const std::string &str )
{
	const char	*stmp;
	char		*endptr;
	double		num;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	if (str.find(".") != std::string::npos)
	{
		stmp = str.c_str();
		num = std::strtod(stmp, &endptr);
		if (endptr != str && std::strlen(endptr) == 1 && *endptr == 'f' && \
				std::abs(num) <= std::numeric_limits<float>::max())
			return (true);
	}
	return (false);
}

/*
 * <cmath>   : std::abs
 * <cstdlib> : std::strtold   (string to long double) 
 * <limits>  : std::numeric_limits<double>
 * <string>	 : find , std::string::npos
 */

bool	ScalarConverter::_isDouble( const std::string &str )
{
	const char	*stmp;
	char		*endptr;
	long double	num;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	if (str.find(".") != std::string::npos)
	{
		stmp = str.c_str();
		num = std::strtold(stmp, &endptr);
    	if (endptr != str && *endptr == '\0' && \
				std::abs(num) <= std::numeric_limits<double>::max())
			return (true);
	}
	return (false);
}

/*
 * Put a message with this conditions :
 *	if (str is printable as char)   // Where X is a char
 *		char: 'X'
 *	else if ( in  range [-128, 127] but no printable) 
 *		char: Non displayable
 *	else if (str is +inf,-inf,nan , +inff, -inff, nanf and outside [-128,127]) :
 *		char: Imposible
 *
 * <cstdlib> : std::atoi, std::atof ( to double), std::isprint
 * <limits>  : std::numeric_limits<char>
 *
 */

void	ScalarConverter::_putChar( const std::string &str, int type )
{
	std::cout << "char: ";
	if ( type == ScalarConverter::_NO_TYPE ||str == "-inf" || str == "+inf" || str == "nan" ||\
			str == "-inff" || str == "+inff" || str == "nanf")
		std::cout << IMPOSSIBLE << std::endl;
	else if (type == ScalarConverter::_T_CHAR)
		std::cout << "'" << str << "'" << std::endl;
	else
	{	
		int			n;
		const char	*stmp;

		stmp = str.c_str();
		if (type == ScalarConverter::_T_INT)
			n = std::atoi(stmp);
		else
			n = static_cast<int> (std::atof(stmp));
		if ( n >= std::numeric_limits<char>::min() && \
				n <= std::numeric_limits<char>::max() && std::isprint(n))
			std::cout << "'" <<  static_cast<char> (n)<< "'" << std::endl;
		else if ( n >= std::numeric_limits<char>::min() && \
				n <= std::numeric_limits<char>::max())
			std::cout << NON_DISPLAY << std::endl;
		else
			std::cout << IMPOSSIBLE << std::endl;
	}
}

/*
 * <cstdlib> : std::atoi, std::atof , std::isprint
 * <limits>  : std::numeric_limits<intr>
 */

void	ScalarConverter::_putInt( const std::string &str, int type )
{
	std::cout << "int: ";
	if ( type == ScalarConverter::_NO_TYPE ||str == "-inf" || str == "+inf" || str == "nan" ||\
			str == "-inff" || str == "+inff" || str == "nanf")
		std::cout << IMPOSSIBLE << std::endl;
	else
	{	
		long int	n;
		const char	*stmp;

		stmp = str.c_str();
		if (type == ScalarConverter::_T_CHAR)
			n  = static_cast<long int> (stmp[0]);   
		else if ( type == ScalarConverter::_T_INT)
			n = std::atoi(stmp);
		else
			n = std::atof(stmp);
		if ( n >= std::numeric_limits<int>::min() && \
				n <=  std::numeric_limits<int>::max())
			std::cout << static_cast<int> (n) << std::endl;
		else
			std::cout << IMPOSSIBLE << std::endl;
	}
}

/*
 *
 * <cmath>   : std::fmod
 * <cstdlib> : std::strtod
 * <limits>  : std::numeric_limits<float>
 */

void	ScalarConverter::_putFloat( const std::string &str, int type )
{
	std::cout << "float: ";
	if (type != ScalarConverter::_NO_TYPE)
	{
		double n;

		if (type == ScalarConverter::_T_CHAR)
			n  = static_cast<double> (str.at(0));   
		else 
			n = std::strtod(str.c_str(), NULL);
		if (n > std::numeric_limits<float>::max())
			std::cout << "+inff" << std::endl;
		else if (n < -std::numeric_limits<float>::max())
			std::cout << "-inff" << std::endl;
		else if (type == ScalarConverter::_T_INT || std::fmod(n, 1.0f) == 0)
			std::cout << static_cast<float> (n) << ".0f" << std::endl;
		else
			std::cout << static_cast<float> (n) << "f" << std::endl;
	}
	else
		std::cout << IMPOSSIBLE << std::endl;
}

/*
 * <cmath>   : std::fmod
 * <cstdlib> : std::atof 
 * <limits>  : std::numeric_limits<double>
 */

void	ScalarConverter::_putDouble( const std::string &str, int type )
{
	long double n;

	std::cout << "double: ";
	if (type != ScalarConverter::_NO_TYPE)
	{
		if (type == ScalarConverter::_T_CHAR)
			n  = static_cast<long double> (str.at(0));   
		else 
			n = std::atof(str.c_str());
		if (n > std::numeric_limits<double>::max())
			std::cout << "+inf" << std::endl;
		else if (n < -std::numeric_limits<double>::max())
			std::cout << "-inf" << std::endl;
		else if (type == ScalarConverter::_T_INT || std::fmod(n, 1.0) == 0)
			std::cout << static_cast<double> (n) << ".0" << std::endl;
		else
			std::cout << static_cast<double> (n) << std::endl;
	}
	else
		std::cout << IMPOSSIBLE << std::endl;
}
/* ------------------- PUBLIC MEMBER FUNCTIONS ------------------*/

/*
 *  Convert str to right typo
 *	Convert str to other typo. If typo convertion error -> put error
 */

void	ScalarConverter::convert( const std::string &str )
{
	int	type;

	type = ScalarConverter::_getScalarType(str);
	ScalarConverter::_putChar(str, type);
	ScalarConverter::_putInt(str, type);
	ScalarConverter::_putFloat(str, type);
	ScalarConverter::_putDouble(str, type);
}
