/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:49:38 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:10:46 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"
#define TOTAL_LEVELS 4

Harl::Harl()
{
}

Harl::~Harl()
{
}

/*
 * See:
 * https://cplusplus.com/forum/beginner/239227/
 * https://www.codeguru.com/cplusplus/c-tutorial-pointer-to-member-function/
 *
 * Those are for undestand concepts:
 * https://www.tutorialspoint.com/function-pointer-to-member-function-in-cplusplus
 * https://www.ibm.com/docs/en/i/7.4?topic=only-pointers-members-c
 * https://www.geeksforgeeks.org/function-pointer-to-member-function-in-cpp/
 */

void	Harl::complain( std::string level )
{
	std::string	levels[TOTAL_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*funcPtr[TOTAL_LEVELS])(void) = {&Harl::_debug, \
	   				&Harl::_info, &Harl::_warning, &Harl::_error};
	enum		levelsEnum {DEBUG, INFO, WARNING, ERROR}; 
	int			i;

	i = -1;
	while ( ++i < TOTAL_LEVELS)
	{
		if (level == levels[i])
			break;
	}
	switch (i)
	{
		case (DEBUG):
			(this->*funcPtr[DEBUG])();
			std::cout << std::endl;
		case (INFO):
			(this->*funcPtr[INFO])();
			std::cout << std::endl;
		case (WARNING):
			(this->*funcPtr[WARNING])();
			std::cout << std::endl;
		case (ERROR):
			(this->*funcPtr[ERROR])();
			break;
		default:	
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}


void	Harl::_debug( void )
{
	std::cout << "[DEBUG]\n I love having extra bacon for my " \
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[INFO]\n I cannot believe adding extra bacon costs more " \
		<< " money. You didn’t put enough bacon in my burger! If you did, " \
		<< "I wouldn’t be asking for more!" << std::endl;
}


void 	Harl::_warning( void )
{
	std::cout << "[WARNING]\n I think I deserve to have some extra bacon for " \
		<< "free. I’ve been coming for years whereas you started working " \
		<< "here since last month." << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ERROR]\n This is unacceptable! I want to speak to the " \
		<< "manager now." << std::endl;
}

