/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myphomebook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:43:36 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/19 12:44:42 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main( void )
{
	PhoneBook	phb;
	std::string	str;

	str = "";
	while (str != "EXIT" )
	{

		std::cout << "Action > ";
		std::getline(std::cin, str);
		if (std::cin.eof() == 0 && str == "ADD")
			phb.add();
		else if (std::cin.eof() == 0 && str == "SEARCH")
			phb.search();
		else if (std::cin.eof() == 1)
		{
			std::cin.clear();
			std::cout << std::endl;
			return (1);
		}
	}
	return (0);
}
