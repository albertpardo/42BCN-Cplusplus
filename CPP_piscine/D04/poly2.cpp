// The video don't has completed code

#include <string>
#include <iostream>

class	ACharacter
{
	private:
		std::string		name;
	public:
		virtual void	attack(std::string const & target) = 0;
		void			sayHello( std::string const & target);
};

class	Warrior : public ACharacter
{
	public:
		void	sayHello(std::string const & target);
};

void	ACharacter::sayHello( std::string const & target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void	Warrior::sayHello( std::string const & target)
{
	std::cout << "*attacks " << target << " whith a sword" << std::endl;
}

class	ICoffeMaker
{
	public:
		virtual void	fillWaterTank( IWaterSource * src ) = 0;
		virtual ICofee*	makeCoffee( std::string const & type ) = 0;
};

int	main()
{
	ACharacter*	a = new Warrior();

	//This would NOT be ok because ACharacter is abstract
	//ACharacter*	b = new ACharacter();

	a->sayHello("students");
	a->attack("roger");

	return (0);
}
