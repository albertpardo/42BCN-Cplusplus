/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:46:18 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/04 10:00:21 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

static void putConvert(std::string const &str)
{
	std::cout << "- convert(\"" << str <<"\")" << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}

static void	test()
{

	std::cout << "=== Subject Examples ===" << std::endl;
	putConvert("0");
	putConvert("nan");
	putConvert("42.0f");
	std::cout << std::endl;
	std::cout << "=== Examples : -inff, +inff, nanf, -inf, +inf  ===" << std::endl;
	putConvert("-inff");
	putConvert("+inff");
	putConvert("nanf");
	putConvert("-inf");
	putConvert("+inf");
	std::cout << std::endl;
	std::cout << "=== Examples :Char limits as chars" << std::endl;
	putConvert(" ");
	putConvert("~");
	std::cout << std::endl;
	std::cout << "=== Examples :Char limits as int" << std::endl;
	putConvert("32");
	putConvert("31");
	putConvert("126");
	putConvert("127");
	putConvert("128");
	putConvert("-128");
	putConvert("-129");
	std::cout << std::endl;
	std::cout << "=== Examples : int limits " << std::endl;
	putConvert("2147483647");
	putConvert("2147483648");
	putConvert("-2147483648");
	putConvert("2147483649");
	std::cout << std::endl;
	std::cout << "=== Examples : float" << std::endl;
	putConvert("42.f");
	putConvert("340283000000000000000000000000000000000.0f");
	putConvert("-340283000000000000000000000000000000000.0f");
	putConvert("340282000000000000000000000000000000000.0f");
	putConvert("-340282000000000000000000000000000000000.0f");
	std::cout << std::endl;
	std::cout << "=== Examples : double" << std::endl;
	putConvert("42.");
	putConvert("179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0");
	putConvert("-179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0");
	putConvert("179770000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0");
	putConvert("-179770000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0");
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else if (argc == 1)
		test();
	else
		std::cout << "Input Error . Use :  ./convert   or   ./convert X  (where X can be any word)" \
		<< std::endl;
	return (0);
}
