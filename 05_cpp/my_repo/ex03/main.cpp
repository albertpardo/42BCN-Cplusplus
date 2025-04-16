/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 07:54:10 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/27 19:23:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

static AForm *	mymakeform(Intern &intern, std::string formname, std::string target)
{
	try
	{
		return (intern.makeForm(formname, target));
	}
	catch (std::exception &e)
	{
		std::cout << "\nException : " << e.what() << std::endl;
		std::cout << std::endl;
	}
	return (NULL);
}

void	test0( void )
{
	Bureaucrat	defaultbureau;
	Bureaucrat	hightbureau("HigthBureau", 1);
	Intern		intern1;
	Intern		intern2;
	AForm		*form1 = NULL;
	AForm		*form2 = NULL;
	AForm		*form3 = NULL;

	std::cout << "\n=== Initial values===" << std::endl;
	std::cout << defaultbureau << std::endl;
	std::cout << hightbureau << std::endl;
	std::cout << std::endl;

	std::cout << "==='intern1' make forms===" << std::endl;
	form1 = mymakeform(intern1, "formTODO", "executorTarget");
	form1 = mymakeform(intern1, "presidential", "executorTarget");
	form2 = mymakeform(intern1, "frobotomy", "executorTarget");
	form3 = mymakeform(intern1, "shruberry", "executorTarget");
	std::cout << std::endl;

	std::cout << "==='defaultbureau' try to sign recent created forms===" << std::endl;
	defaultbureau.signForm(*form1);	
	defaultbureau.signForm(*form2);	
	defaultbureau.signForm(*form3);	
	std::cout << std::endl;

	std::cout << "==='hightbureau' try to sign recent created forms===" << std::endl;
	hightbureau.signForm(*form1);	
	hightbureau.signForm(*form2);	
	hightbureau.signForm(*form3);	
	std::cout << std::endl;

	std::cout << "===created forms status===" << std::endl;
	std::cout << *form1 << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;
	std::cout << std::endl;

	std::cout << "==='defaultbureau' try to execute recent signed forms===" << std::endl;
	defaultbureau.executeForm(*form1);
	defaultbureau.executeForm(*form2);
	defaultbureau.executeForm(*form3);
	std::cout << std::endl;

	std::cout << "==='hightbureau' try to execute recent signed forms===" << std::endl;
	hightbureau.executeForm(*form1);
	hightbureau.executeForm(*form2);
	hightbureau.executeForm(*form3);
	std::cout << std::endl;

	std::cout << "==='intern2 = intern1', new form using '*form1' ===" << std::endl;
	delete(form1);
	intern2	= intern1;
	form1 = mymakeform(intern2, "presidential", "otherTarget");
	hightbureau.signForm(*form1);	
	hightbureau.executeForm(*form1);
	std::cout << std::endl;

	delete(form1);
	delete(form2);
	delete(form3);
}

int main( void )
{
	test0();
}
