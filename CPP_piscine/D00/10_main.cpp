/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:50:26 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/20 15:58:06 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class10.hpp"

int	main(void)
{
	Sample	instance1( 42 );
	Sample	instance2( 42 );

	if ( &instance1 == &instance1)
		std::cout << "instance1 and instance1 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are not physically equal" << std::endl;

	if ( &instance1 == &instance2)
		std::cout << "instance1 and instance2 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are not physically equal" << std::endl;

	if ( instance1.compare( &instance1 ) == 0 )
		std::cout << "instance1 and instance1 are structurally equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are not structurally equal" << std::endl;

	if ( instance1.compare( &instance2 ) == 0 )
		std::cout << "instance1 and instance2 are structurally equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are not structurally equal" << std::endl;

	return (0);
}
