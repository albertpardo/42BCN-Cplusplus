/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:40:18 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:40:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	 zombieHorde( int N, std::string name )
{
	int		i;	
	Zombie *horde = new Zombie[N];

	i = -1;
	while (++i < N)
		horde[i].setName(name); 
	return (horde);
}
