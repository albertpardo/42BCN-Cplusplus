/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:45:31 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/28 15:53:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( void )
{
	Data		originalData;
	uintptr_t	raw;
	Data		*deserializeRaw;

	originalData.numInt = 1;
	originalData.numFloat = 100.0f;

	std::cout << "---- 'originalData' Info ----" << std::endl;
	std::cout << "&originalData            :  " << &originalData << std::endl;
	std::cout << "originalData.numInt = " << originalData.numInt << std::endl;
	std::cout << "originalData.numFloat = " << originalData.numFloat << std::endl;
	std::cout << std::endl;
	
	raw = Serializer::serialize(&originalData);
	std::cout << "---- 'raw' gets the rigth Address Memory of 'originalData' ----" << std::endl;
	std::cout << "&raw                      : " << &raw << std::endl;
	std::cout << "raw value in Hexadecimal  : " << "0x" << std::hex << raw << std::endl;
	std::cout << std::endl;

	deserializeRaw = Serializer::deserialize(raw);
	std::cout << "---- '*deserializeRaw' gets the rigth Address Memory of originalData and 'Data var' can acces to 'originalData' ----" << std::endl;
	std::cout << "&deserializeRaw           : " << &deserializeRaw << std::endl;
	std::cout << "deserializeRaw            : " << deserializeRaw << std::endl;
	std::cout << "deserializeRaw.numInt = " << deserializeRaw->numInt << std::endl;
	std::cout << "deserializeRaw.numFloat = " << deserializeRaw->numFloat << std::endl;

}
