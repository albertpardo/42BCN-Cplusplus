/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:46:48 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/20 12:14:43 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <locale>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	this->_nextidfree = 0;
//	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook( void )
{
//	std::cout << "PhoneBook destructor called" << std::endl;
}

bool		PhoneBook::_isNum( std::string str) const
{
	std::locale	loc;
	bool		res;
	int			i;

	res = true;
	i = -1;
	if (str[0] != '\0')
	{
		while (res && str[++i] != '\0')
		{
			if ( !std::isdigit(str[i], loc))
				res = false;
		}
	}
	else
		res = false;
	return (res);
}

void	PhoneBook::_putStrFormat( std::string str1, std::string str2) const
{
	if (str1.size() > 10)
		str1 = str1.substr(0, 9)  + ".";
	std::cout << std::setw(10) << str1 << str2;
}

void	PhoneBook::_putPhoneBook( void ) const
{

	int	index;

	index = 0;
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "Nick Name" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	while (index < 8)
	{
		std::cout << std::setw(10) << index << "|";
		_putStrFormat(PhoneBook::_contacts[index].get_fname(), "|");
		_putStrFormat(PhoneBook::_contacts[index].get_lname(), "|");
		_putStrFormat(PhoneBook::_contacts[index].get_nickname(), "\n");
		index++;
	}
}

std::string	PhoneBook::_getStrCli( std::string msg ) const
{
	std::string	str;

	str = "";
	while (!std::cin.eof() && str.empty())
	{
		std::cout << msg;
		std::getline(std::cin, str);
	}
	return (str);
}

int		PhoneBook::_askIndex( void ) const
{
	std::string	str;
	int			i;

	i = -1;
	while (i == -1)
	{
		str = _getStrCli("Enter Index: ");
		if (str.size() == 1 && str[0] >= '0' && str[0] < '8')
			i = str[0] - '0';
		else
			std::cout << "Invalid index" << std::endl;
	}
	return (i);
}

void	PhoneBook::_putContact( int i) const
{
	Contact	contact;

	contact = this->_contacts[i];
	std::cout << "First Name    : " << contact.get_fname() << std::endl;
	std::cout << "Last Name     : " << contact.get_lname() << std::endl;
	std::cout << "Nickname      : " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number  : " << contact.get_phone() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}

void	PhoneBook::add( void )
{
	std::string	str;
	Contact		*contact;
	
	contact	= &this->_contacts[this->_nextidfree];
	str = _getStrCli("Enter First Name  : ");
	contact->set_fname(str);
	str = _getStrCli("Enter Last Name   : ");
	contact->set_lname(str);
	str = _getStrCli("Enter Nick Name   : ");
	contact->set_nickname(str);
	str = "";
	while (str.size() != 9 || (str.size() == 9 && !_isNum(str)))
		str = _getStrCli("Enter Phone Number (it must be 9 digits): ");
	contact->set_phone(str);
	str = _getStrCli("Enter Dark Secret : ");
	contact->set_secret(str);
	this->_nextidfree++;
	if (this->_nextidfree == 8)
		this->_nextidfree = 0;
}

void	PhoneBook::search(void)
{
	int	i;
	
	PhoneBook::_putPhoneBook();
	i = PhoneBook::_askIndex();
	PhoneBook::_putContact(i);
}
