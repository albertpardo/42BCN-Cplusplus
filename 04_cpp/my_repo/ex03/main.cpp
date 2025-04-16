/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:32:19 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/19 12:47:01 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

static void	subjectTest( void )
{
	std::cout << "// ---------- Subject test ---------- //" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	
	std::cout << "// ---------- END Subject test ------ //" << std::endl;
}

static void	myTestOne( void )
{
	std::cout << "\n// ---------- START myTestOne ---------- //" << std::endl;

	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character*	me = new Character("me");
	AMateria	*tmp, *tmp1;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << "\n==== Inventory Object 'me'=======" << std::endl;
	me->showInventory();
	std::cout << "\n==== END Inventory Object 'me'=======" << std::endl;
	std::cout << "\n/=> Start unequip and Inventory 'me' <=/" << std::endl;
	std::cout << "\n> tmp = me->getMateria(0)" << std::endl;  
	tmp = me->getMateria(0);
	std::cout << "tmp -> (" << tmp << "), " << tmp->getType() << std::endl; 
	std::cout << "\n> me->unequip(0)" << std::endl;  
	me->unequip(0);
	std::cout << "\n==== Inventory Object 'me'=======" << std::endl;
	me->showInventory();
	std::cout << "\n==== END Inventory Object 'me'=======" << std::endl;
	std::cout << "\n> tmp1 = me->getMateria(1)" << std::endl;
	tmp1 = me->getMateria(1);
	std::cout << "tmp1 -> (" << tmp << "), " << tmp->getType() << std::endl; 
	std::cout << "\n> me->unequip(1)" << std::endl;  
	me->unequip(1);
	std::cout << "\n==== Inventory Object 'me'=======" << std::endl;
	me->showInventory();
	std::cout << "\n==== END Inventory Object 'me'=======" << std::endl;
	std::cout << "\n/=> END unequip and Inventory 'me' <=/" << std::endl;

	delete tmp1;	
	delete tmp;	

	delete me;
	delete src;
	
	std::cout << "\n// ---------- END myTestOne ------ //" << std::endl;
}

int main ( void )
{
	subjectTest();
	myTestOne();

	return (0);
}
