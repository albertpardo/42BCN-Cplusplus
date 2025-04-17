/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:06:36 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/21 08:49:43 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class11.hpp"

void	f0( void )
{
	Sample	instance;

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;

	return;
}

void	f1( void )
{
	Sample	instance;

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	f0();

	return;
}

int	main(void)
{
	Sample	instance;

	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances : " << Sample::getNbInst() << std::endl;

	return (0);
}
