/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:06:45 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 17:06:49 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

# define MAX_IDEAS 100
class Brain
{
	private:
		std::string	_ideas[MAX_IDEAS];

	public:
		Brain( void );
		Brain(Brain& other);
		Brain& operator = ( const Brain& other );
		~Brain( void );
};

#endif
