/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:59:52 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/27 18:03:36 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	test0( void )
{
	Bureaucrat				defaultbureau;
	Bureaucrat				b145("b145", 145);
	Bureaucrat				b72("b72", 72);
	Bureaucrat				b25("b25", 25);
	Bureaucrat				hightbureau("HigthBureau", 1);
	ShrubberyCreationForm 	fshru1("FormShru1");
	RobotomyRequestForm		frobot1("FormRobot1");
	PresidentialPardonForm	fpresi("FormPresi");

	std::cout << "\n=== Initial values===" << std::endl;
	std::cout << defaultbureau << std::endl;
	std::cout << b145 << std::endl;
	std::cout << b72 << std::endl;
	std::cout << b25 << std::endl;
	std::cout << hightbureau << std::endl;
	std::cout << fshru1 << std::endl;
	std::cout << frobot1 << std::endl;
	std::cout << fpresi << std::endl;
	std::cout << std::endl;

	std::cout << "==='defaultbureau' try to sign===" << std::endl;
	defaultbureau.signForm(fshru1);	
	defaultbureau.signForm(frobot1);
	defaultbureau.signForm(fpresi);
	std::cout << std::endl;

	std::cout << "==='defaultbureau' try to execute no signed forms===" << std::endl;
	defaultbureau.executeForm(fshru1);
	defaultbureau.executeForm(frobot1);
	defaultbureau.executeForm(fpresi);
	std::cout << std::endl;

	std::cout << "==='b145' try to sign===" << std::endl;
	b145.signForm(fshru1);
	b145.signForm(frobot1);
	b145.signForm(fpresi);
	std::cout << std::endl;

	std::cout << "==='defaultbureau' and 'b145' try to execute signed form fshru1===" << std::endl;
	defaultbureau.executeForm(fshru1);
	b145.executeForm(fshru1);
	std::cout << std::endl;

	std::cout << "==='b72' try to execute signed form fshru1===" << std::endl;
	b72.executeForm(fshru1);
	std::cout << std::endl;

	std::cout << "==='b72' try to sign the signed form fshru1===" << std::endl;
	b72.signForm(fshru1);
	std::cout << std::endl;

	std::cout << "==='hightbureau' try to sign===" << std::endl;
	hightbureau.signForm(fshru1);
	hightbureau.signForm(frobot1);
	hightbureau.signForm(fpresi);
	std::cout << std::endl;

	std::cout << "=== Actual forms status===" << std::endl;
	std::cout << fshru1 << std::endl;
	std::cout << frobot1 << std::endl;
	std::cout << fpresi << std::endl;
	std::cout << std::endl;

	std::cout << "==='defaultbureau' try to execute signed forms===" << std::endl;
	defaultbureau.executeForm(fshru1);
	defaultbureau.executeForm(frobot1);
	defaultbureau.executeForm(fpresi);
	std::cout << std::endl;

	std::cout << "==='b145' try to execute signed forms===" << std::endl;
	b145.executeForm(fshru1);
	b145.executeForm(frobot1);
	b145.executeForm(fpresi);
	std::cout << std::endl;

	std::cout << "==='b72' try to execute signed forms===" << std::endl;
	b72.executeForm(fshru1);
	b72.executeForm(frobot1);
	b72.executeForm(fpresi);
	std::cout << std::endl;

	std::cout << "==='b25' try to execute signed forms===" << std::endl;
	b25.executeForm(fshru1);
	b25.executeForm(frobot1);
	b25.executeForm(fpresi);
	std::cout << std::endl;

	std::cout << "==='hightbureau' try to execute signed forms===" << std::endl;
	hightbureau.executeForm(fshru1);
	hightbureau.executeForm(frobot1);
	hightbureau.executeForm(fpresi);
	std::cout << std::endl;

	std::cout << "===Test RobotomyRequestForm output (50%)===" << std::endl;
	int	i = -1;
	while (++i < 10)
	{	
		std::cout << "----- i = " << i + 1 << " -> ";
		hightbureau.executeForm(frobot1);
	}
	std::cout << std::endl;

	std::cout << "===Test '=' assignament for forms===" << std::endl;

	ShrubberyCreationForm 	othfshru1;
	RobotomyRequestForm		othfrobot1;
	PresidentialPardonForm	othfpresi;

	std::cout << "--- forms : othfshru1, othfrobot1, othfpresi after being constructed '=' ---" << std::endl;
	std::cout << "othfshru1  > " << othfshru1 << std::endl;
	std::cout << "othfrobot1 > " << othfrobot1 << std::endl;
	std::cout << "othfpresi  > " << othfpresi << std::endl;
	othfshru1 = fshru1;
	othfrobot1 = frobot1;
	othfpresi = fpresi;
	std::cout << "--- Original forms ---" << std::endl;
	std::cout << "fshru1     > " << fshru1 << std::endl;
	std::cout << "frobot1    > " << frobot1 << std::endl;
	std::cout << "fpresi     > " << fpresi << std::endl;
	std::cout << "--- forms : othfshru1, othfrobot1, othfpresi after '=' is used ---" << std::endl;
	std::cout << "othfshru1  > " << othfshru1 << std::endl;
	std::cout << "othfrobot1 > " << othfrobot1 << std::endl;
	std::cout << "othfpresi  > " << othfpresi << std::endl;
	std::cout << std::endl;

	std::cout << "===Test copy constructor forms===" << std::endl;

	ShrubberyCreationForm 	copyfshru1(fshru1);
	RobotomyRequestForm		copyfrobot1(frobot1);
	PresidentialPardonForm	copyfpresi(fpresi);

	std::cout << "--- forms : copyfshru1, copyfrobot1, copyfpresi after being constructed by copy ---" << std::endl;
	std::cout << "copyfshru1  > " << copyfshru1 << std::endl;
	std::cout << "copyfrobot1 > " << copyfrobot1 << std::endl;
	std::cout << "copyfpresi  > " << copyfpresi << std::endl;
	std::cout << std::endl;
}

int main( void )
{
		test0();
}
