/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:23:21 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/19 13:24:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale> 
#include <iostream>
#include <string>

int	main( int argc, char **argv )
{
	
	std::locale	loc;
	int			i;
	int			j;

	j = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && argv[++j])
	{
		i = -1;
		while ( argv[j][++i] != '\0')
			std::cout << std::toupper(argv[j][i],loc);
	}
	std::cout << std::endl;
	return (0);
}
