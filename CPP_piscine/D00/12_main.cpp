/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:01:54 by apardo-m          #+#    #+#             */
/*   Updated: 2024/03/21 10:03:01 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class12.hpp"

int	main(void)
{
	Sample		instance;
	Sample *	instancep = &instance;  // Se define una instancia del tipo puntero

	// Estas dos  lineas parece que son como si se añadieran a la class Sample (Por defecto parecen publicas)
	int			Sample::*p = NULL;			// Puntero tipo int
	void		(Sample::*f)(void) const;	// puntero a función

	p = &Sample::foo; // el puntero apunta a la variable publica de Sample 

	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	
	f = &Sample::bar;  //El puntero a función apunta a la función publica de Sample

	(instance.*f)();	//llamada a la función via puntero desde instancia standard
	(instancep->*f)(); //llamada a la función via puntero desde instancia tipo puntero

	return (0);
}

/*
 * 240321  No lo entiendo
 *
 * Parece que se pueden añadir nuevas variables a una instancia desde el programa y sin que aparezcan en el 'hpp' ni en el 'cpp' de la instancia/clase
 */
