/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:14:05 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/23 14:18:15 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "BitcoinExchange.hpp"

int	 main( int argc, char **argv )
{
	BitcoinExchange	btc;

	if (argc == 2)
	{
		try
		{
			btc.loadRates("data.csv");
			btc.getExchange(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: could not open file. Use: './btc [exchanges file]'" << std::endl;
	return (0);
}
