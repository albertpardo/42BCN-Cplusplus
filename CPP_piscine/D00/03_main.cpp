/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:21:09 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/16 14:01:03 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class03.hpp"

int	main(void)
{
	Sample	instance;

	instance.foo = 42;
	std::cout << "instance.foo: " << instance.foo << std::endl;
	
	instance.bar();

	return (0);
}
