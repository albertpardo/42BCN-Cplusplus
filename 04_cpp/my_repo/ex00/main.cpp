/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:02:23 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/18 14:22:40 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	testAnimals( void )
{
	std::cout << "/----- START : test animals -----/" << std::endl;
	const Animal* animal = new Animal();
	const Animal* animalDog = new Dog();
	const Animal* animalCat = new Cat();

	std::cout << animalDog->getType() << std::endl;
	std::cout << animalCat->getType() << std::endl;
	animalCat->makeSound();
	animalDog->makeSound();
	animal->makeSound();
	
	std::cout << "\n>>delete animal;<<" << std::endl;
	delete animal;
	std::cout << "\n>>delete animalDog;<<" << std::endl;
	delete animalDog;
	std::cout << "\n>>delete animalCat;<<" << std::endl;
	delete animalCat;
	std::cout << "/----- END : test animals -----/\n" << std::endl;
}

static void	testCopyAnimals( void )
{
	std::cout << "/----- START : Copy test animals -----/" << std::endl;
	const Animal* animal = new Animal();
	const Animal* animalDog = new Dog();
	const Animal* animalCat = new Cat();
	
	std::cout << "\n** Two Copies as Animal ** " << std::endl;
	const Animal* animalCp = new Animal(*animal);
	const Animal* animalDogCp = new Animal(*animalDog);
	std::cout << "\n** Copy as Cat ** " << std::endl;
	const Cat* animalCatCp = new Cat(*static_cast<const Cat *>(animalCat));
	std::cout << "\n** Assigned Cat object** " << std::endl;
	Cat assignedCat;
	std::cout << "\n** Assignation Cat object** " << std::endl;
	assignedCat = *animalCatCp;

	std::cout << "\n --- Sounds : " << std::endl;
	std::cout << ">>animalCatCp->makeSound()<<" << std::endl;
	animalCatCp->makeSound();
	std::cout << "\n>>animalDogCp->makeSound()<<" << std::endl;
	animalDogCp->makeSound();
	std::cout << "\n>>animalCp->makeSound()<<" << std::endl;
	animalCp->makeSound();
	std::cout << "\n>>assignedCat->makeSound()<<" << std::endl;
	assignedCat.makeSound();

	std::cout << "\n-- Delete copies --" << std::endl;
	std::cout << "\n>>delete animalCp;<<" << std::endl;
	delete animalCp;
	std::cout << "\n>>delete animalDogCp;<<" << std::endl;
	delete animalDogCp;
	std::cout << "\n>>delete animalCatCp;<<" << std::endl;
	delete animalCatCp;
	std::cout << "\n-- Delete originals --" << std::endl;
	std::cout << "\n>>delete animal;<<" << std::endl;
	delete animal;
	std::cout << "\n>>delete animalDog;<<" << std::endl;
	delete animalDog;
	std::cout << "\n>>delete animalCat;<<" << std::endl;
	delete animalCat;

	std::cout << "/----- END : Copy test animals -----/" << std::endl;
}

static void	testRightAnimals( void )
{
	std::cout << "\n/----- START : polyanimals -----/" << std::endl;
	const Dog* dog = new Dog();
	const Cat* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << "\n--- Sounds : " << std::endl;
	cat->makeSound();
	dog->makeSound();

	std::cout << "\n-- Delete animals --" << std::endl;
	delete dog;
	delete cat;
	std::cout << "/----- END : polyanimals -----/" << std::endl;
}

static void	testWrongAnimals()
{
	std::cout << "\n/----- START : WRONG animals -----/" << std::endl;
	const WrongAnimal* animal = new WrongAnimal();
	const WrongAnimal* animalCat = new WrongCat();
	const WrongCat* wrongCat = new WrongCat();

	std::cout << animalCat->getType() << std::endl;
	std::cout << "\n--- Sounds : " << std::endl;
	animalCat->makeSound();
	animal->makeSound();
	wrongCat->makeSound();

	std::cout << "\n-- Delete Wrong animals --" << std::endl;
	delete animal;
	delete animalCat;
	delete wrongCat;
	std::cout << "/----- END : WRONG animals -----/" << std::endl;
}

int main( void )
{
	testAnimals();
	testCopyAnimals();
	testRightAnimals();
	testWrongAnimals();

	return (0);
}
