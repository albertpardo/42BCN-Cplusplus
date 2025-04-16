/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:45:34 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/17 14:39:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap(const ClapTrap& othTrap);
		ClapTrap& operator = (const ClapTrap& othTrap);
		~ClapTrap( void );

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
};

#endif
