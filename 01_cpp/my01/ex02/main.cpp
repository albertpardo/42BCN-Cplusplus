/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:41:50 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:41:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str; 

	std::cout << "   str allocated at memory adddress = " << &str << std::endl;
	std::cout << "*stringPTR points to memory address = " << stringPTR << std::endl;
	std::cout << " stringREF points to memory address = " << &stringREF << std::endl;
	std::cout << "       str Value = " << str << std::endl;
	std::cout << "*stringPTR Value = " << *stringPTR << std::endl;
	std::cout << " stringREF Value = " << stringREF << std::endl;
}
