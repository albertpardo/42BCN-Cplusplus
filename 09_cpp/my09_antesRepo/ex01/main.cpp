/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:03:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/12 14:42:39 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	 main( int argc, char **argv )
{
	if (argc == 2)
	{
		try
		{
			execRpn(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: No arguments. Use: './btc \"[RPN formula]\"" << std::endl;

	return (0);
}
