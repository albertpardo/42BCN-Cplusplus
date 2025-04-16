/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:21:49 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/27 15:05:39 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test0( void )
{
	std::cout << "/********** test 0 *************************/" << std::endl;
	std::cout << "--- Form    Bad1(\"Bad1\", 0, 1);" << std::endl;
	try
	{
		Form	Bad1("Bad1", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "\nException : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Form    Bad2(\"Bad2\", 1, 0);" << std::endl;
	try
	{
		Form	Bad2("Bad2", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "\nException : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "--- Form    Bad3(\"Bad3\", 200, 1);" << std::endl;
	try
	{
		Form	Bad3("Bad3", 200, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "\nException : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Form    Bad4(\"Bad4\", 1,300);" << std::endl;
	try
	{
		Form	Bad4("Bad4", 1, 300);
	}
	catch (std::exception &e)
	{
		std::cout << "\nException : " << e.what() << std::endl;
	}
	std::cout << std::endl;

}

void	test1( void )
{
	std::cout << "/********** test 1 *************************/" << std::endl;
	Bureaucrat	defaultbureau;
	Bureaucrat	lowbureau("LowBureau", 140);
	Bureaucrat	hightbureau("HigthBureau", 1);
	Form		defaultform;
	Form		hightformone("HightFormOne", 1, 150);
	Form		hightformtwo("HightFormTwo", 2, 149);
	Form		lowform("LowForm",150,150);

	std::cout << "\n--- Initial values---" << std::endl;
	std::cout << defaultbureau << std::endl;
	std::cout << lowbureau << std::endl;
	std::cout << hightbureau << std::endl;
	std::cout << defaultform << std::endl;
	std::cout << lowform << std::endl;
	std::cout << hightformone << std::endl;
	std::cout << hightformtwo << std::endl;
	std::cout << std::endl;
	std::cout << "---Copy construct from 'hightformone' to 'copyform'---" << std::endl;
	Form		copyform(hightformone);
	std::cout << "hightformone : " << hightformone << std::endl;
	std::cout << "copyform  : " << copyform << std::endl;
	std::cout << std::endl;
	std::cout << "---Using equal : 'defaultform = hightformone' (only _issigned is change , rest of vars are constants)---" << std::endl;
	defaultform = hightformone;
	std::cout << "hightformone   : " << hightformone << std::endl;
	std::cout << "defaultform : " << defaultform << std::endl;
	std::cout << std::endl;
	std::cout << "--Firm allowed-" << std::endl;
	lowbureau.signForm(lowform);
	hightbureau.signForm(hightformone);
	std::cout << std::endl;
	std::cout << "--No allowed Firm-" << std::endl;
	lowbureau.signForm(hightformtwo);
	std::cout << std::endl;
	std::cout << "\n--- Form final values---" << std::endl;
	std::cout << defaultform << std::endl;
	std::cout << lowform << std::endl;
	std::cout << hightformone << std::endl;
	std::cout << hightformtwo << std::endl;
	std::cout << std::endl;
}

int main( void )
{
	test0();
	test1();
	return (0);
}
