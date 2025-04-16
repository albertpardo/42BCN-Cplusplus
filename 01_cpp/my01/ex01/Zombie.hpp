/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:40:54 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:41:12 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie( void );
		~Zombie( void );
		void	setName( std::string name );
		void	announce( void );
};

Zombie*	 zombieHorde( int N, std::string name );

#endif
