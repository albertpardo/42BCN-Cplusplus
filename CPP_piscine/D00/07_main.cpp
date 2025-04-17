/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:50:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/20 14:33:59 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class07.hpp"

int	main(void)
{
	Sample	instance;

	instance.publicFoo = 42;
	//std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;

	instance._privateFoo = 42;
	//std::cout << "instance._privateFoo: " << instance._privateFoo << std::endl;

	instance.publicBar();
	//instance._privateBar();

	return (0);
}
