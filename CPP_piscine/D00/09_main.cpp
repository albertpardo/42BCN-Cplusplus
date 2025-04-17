/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:50:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/20 16:16:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class09.hpp"

int	main(void)
{
	Sample	instance;

	instance.setFoo( 42 );
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
	instance.setFoo( -42 );
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
	return (0);
}
