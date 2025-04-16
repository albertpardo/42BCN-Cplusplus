/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:42:52 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/19 12:42:57 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{
}

Contact::~Contact( void )
{
}

std::string		Contact::get_fname( void ) const
{
	return (this->_fname);
}

std::string		Contact::get_lname( void ) const
{
	return (this->_lname);
}

std::string		Contact::get_nickname( void ) const
{
	return (this->_nickname);
}

std::string		Contact::get_phone( void ) const
{
	return (this->_phone);
}

std::string		Contact::get_secret( void ) const
{
	return (this->_secret);
}

void	Contact::set_fname( std::string str )
{
	this->_fname = str;	
}

void	Contact::set_lname( std::string str )
{
	this->_lname = str;	
}

void	Contact::set_nickname( std::string str )
{
	this->_nickname = str;	
}

void	Contact::set_phone( std::string str )
{
	this->_phone = str;	
}

void	Contact::set_secret( std::string str )
{
	this->_secret = str;	
}
