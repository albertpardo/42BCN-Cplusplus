/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:41:43 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/28 17:07:59 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;
	
	if (argc == 2)
		harl.complain( argv[1]);
	else
	{
		std::cout << "Use : \n ./harlFiler WarningLevel \n or \n ./harl \"" \
			<< "WarningLevel\"" << std::endl;
		std::cout << "Where WarningLevel can be: DEBUG, INFO, WARNING, ERROR." \
		   	<< std::endl;
		return (1);
	}
	return (0);
}
