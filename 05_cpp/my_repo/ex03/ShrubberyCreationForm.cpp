/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:43:37 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/17 08:54:16 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

#define G_SIGN 145
#define G_EXEC 137
#define SHRU_NAME "ShrubberyCreationForm"

/*  --- Orthodox Canonical Form Functions (Public)--- */

ShrubberyCreationForm::ShrubberyCreationForm( void ) : \
	AForm::AForm(SHRU_NAME, G_SIGN, G_EXEC), _target("DefaultTarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target) : \
	AForm::AForm(SHRU_NAME, G_SIGN, G_EXEC), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &oth ) : \
	AForm::AForm(oth), _target(oth._target)
{
}

/* 
 * Call operator of base class:
 * https://stackoverflow.com/questions/4734846/calling-operators-of-base-class-safe
 */

ShrubberyCreationForm & ShrubberyCreationForm::operator = ( const ShrubberyCreationForm &oth )
{
	AForm::operator=(oth);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}
		
/* --- Other Public functions ---*/

/* https://ascii.co.uk/art/tree */

void ShrubberyCreationForm::executeForm( void ) const
{
	std::ofstream		file;
	const std::string	name = this->_target + "_shrubbery";
	const char			*filename = name.c_str();
	int 				i = -1;
	file.open(filename);
	if (!file.fail())
	{
		while (++i < 2)
		{
	        file << "                                                .\n"
				<< "                                     .         ;\n"
				<< "        .              .              ;%     ;;\n"
				<< "         ,           ,                :;%  %;\n"
				<< "          :         ;                   :;%;'     .,\n"
				<< " ,.        %;     %;            ;        %;'    ,;\n"
				<< "   ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
				<< "    %;       %;%;      ,  ;       %;  ;%;   ,%;'\n" 
				<< "     ;%;      %;        ;%;        % ;%;  ,%;'\n"
				<< "      `%;.     ;%;     %;'         `;%%;.%;'\n"
				<< "       `:;%.    ;%%. %@;        %; ;@%;%'\n"
				<< "          `:%;.  :;bd%;          %;@%;'\n"
				<< "            `@%:.  :;%.         ;@@%;'\n"
				<< "             `@%.  `;@%.      ;@@%;\n"
				<< "               `@%%. `@%%    ;@@%;\n"
				<< "                 ;@%. :@%%  %@@%;\n"
				<< "                   %@bd%%%bd%%:;\n"
				<< "                     #@%%%%%:;;\n"
				<< "                     %@@%%%::;\n"
				<< "                     %@@@%(o);  . '\n"
				<< "                     %@@@o%;:(.,'\n"
				<< "                 `.. %@@@o%::;\n"
				<< "                    `)@@@o%::;\n"
				<< "                     %@@(o)::;\n"
				<< "                    .%@@@@%::;\n"
				<< "                    ;%@@@@%::;.\n"
				<< "                    ;%@@@@%%:;;;.\n"
				<< "                 ...;%@@@@@%%:;;;;,.." << std::endl;
			file << std::endl;
		}
		file.close();
 	}
	else
		std::cerr << "Error opening file." << std::endl;
}
