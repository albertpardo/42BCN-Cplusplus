/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:48:09 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/19 16:35:59 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class	PhoneBook
{
	private:
	
		Contact		_contacts[8];
		int			_nextidfree;

		bool		_isNum( std::string str) const;
		void		_putStrFormat( std::string str1, std::string str2) const;
		void		_putPhoneBook( void ) const;
		std::string	_getStrCli( std::string msg ) const;
		int			_askIndex( void ) const;
		void		_putContact( int i) const;

	public:
		
		PhoneBook( void );
		~PhoneBook( void );
		void		add( void );
		void		search( void );
};

#endif
