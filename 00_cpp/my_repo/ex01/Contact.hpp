/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:47:43 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/19 12:47:47 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{

	private:

		std::string		_fname;
		std::string		_lname;
		std::string		_nickname;
		std::string		_phone;
		std::string		_secret;

	public:

		Contact( void );
		~Contact( void );

		std::string		get_fname( void ) const;
		std::string		get_lname( void ) const;
		std::string		get_nickname( void ) const;
		std::string		get_phone( void ) const;
		std::string		get_secret( void ) const;
		void			set_fname( std::string str);
		void			set_lname( std::string str);
		void			set_nickname( std::string str);
		void			set_phone( std::string str);
		void			set_secret( std::string str);
};

#endif
