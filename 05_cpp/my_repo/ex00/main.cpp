/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:05:10 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/27 11:05:17 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"

void	test0( void )
{
	Bureaucrat	defaultbureau;
	Bureaucrat	lowbureau("LowBureau", 149);
	Bureaucrat	hightbureau("HigthBureau", 3);

	std::cout << "\n--- Initial values---" << std::endl;
	std::cout << defaultbureau << std::endl;
	std::cout << lowbureau << std::endl;
	std::cout << hightbureau << std::endl;
	std::cout << std::endl;
	std::cout << "---Copy construct from 'hightbureau' to 'copybureau'---" << std::endl;
	Bureaucrat	copybureau(hightbureau);
	std::cout << "hightbureau : " << hightbureau << std::endl;
	std::cout << "copybureau  : " << copybureau << std::endl;
	std::cout << std::endl;
	std::cout << "---Using equal : 'defaultbureau = hightbureau' (only grade is change , name is a constant)---" << std::endl;
	defaultbureau = hightbureau;
	std::cout << "hightbureau   : " << hightbureau << std::endl;
	std::cout << "defaultbureau : " << defaultbureau << std::endl;
	std::cout << std::endl;
	std::cout << "---'lowbureau.decrementGrade()' and 'hightbureau.incrementGrade()'---" << std::endl;
	lowbureau.decrementGrade();
	hightbureau.incrementGrade();
	std::cout << lowbureau << std::endl;
	std::cout << hightbureau << std::endl;
	std::cout << std::endl;
}

void	test1( void )
{
	Bureaucrat	lowbureau("LowBureau", 149);

	std::cout << "\n--- Initial values---" << std::endl;
	std::cout << lowbureau << std::endl;
	std::cout << std::endl;
	std::cout << "--- Expectected exception using : 'lowbureau.decrementGrade()' two times---" << std::endl;
	lowbureau.decrementGrade();
	std::cout << lowbureau << std::endl;
	lowbureau.decrementGrade();
	std::cout << lowbureau << std::endl;
}

void	test2( void )	
{
	Bureaucrat	hightbureau("HigthBureau", 3);

	std::cout << "\n--- Initial values---" << std::endl;
	std::cout << hightbureau << std::endl;
	std::cout << std::endl;
	std::cout << "--- Expectected exception using : 'hightbureau.incrementGrade() in third time'---" << std::endl;
	hightbureau.incrementGrade();
	std::cout << hightbureau << std::endl;
	hightbureau.incrementGrade();
	std::cout << hightbureau << std::endl;
	hightbureau.incrementGrade();
	std::cout << hightbureau << std::endl;
}

void	test3( void )
{
	std::cout << "--- Expectected exception using : 'badHightBureau(\"badHightBureau\", 0)'---" << std::endl;
	Bureaucrat	badHightBureau("badHightBureau", 0);
}

void	test4( void )
{
	std::cout << "--- Expectected exception using : 'badLowBureau(\"badLowBureau\", 151)'---" << std::endl;
	Bureaucrat	badLowBureau("badLowBureau", 151);
}

int main( int argc, char *argv[] )
{
	std::string	val;

	if (argc < 3)
	{
		if (argc == 2)
		{
			val = argv[1];
			if ( val != "1" && val != "2" && val != "3" && val != "4")
			{
				std::cout << "Use : './bureauctat' or './bureaucrat X' where X is in [1,4]" << std::endl;
				return (1);
			}
		}
		try
		{
			if (argc == 1)
				test0();
			else if (val == "1")
				test1();
			else if (val == "2")
				test2();
			else if (val == "3")
				test3();
			else if (val == "4")
				test4();
		}
		catch (std::exception &e)
		{
			std::cout << "\nException : " << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Use : './bureauctat' or './bureaucrat X' where X is in [1,4]" << std::endl;
		return (1);
	}
	return (0);
}
