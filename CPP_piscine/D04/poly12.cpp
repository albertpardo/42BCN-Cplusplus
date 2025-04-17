#include <string>
#include <iostream>

class	Character
{
	public:
		virtual void	sayHello( std::string const & target);
};

class	Warrior : public Character
{
	public:
		void	sayHello(std::string const & target);
};

class	Cat
{
	private:
		int		_numberOfLegs;

	public:
		Cat();
		Cat( Cat const &);
		Cat& operator=( Cat const &);
		~Cat();

		void	run(int distance);

		void	scornSomeone(std::string const & target);
};

void	Character::sayHello( std::string const & target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void	Warrior::sayHello( std::string const & target)
{
	std::cout << "F**** off " << target << ", I don't like you !" << std::endl;
}

int	main()
{
	//This is OK, obviously, Warrior IS a Wattior

	Warrior*	a = new Warrior();

	//This is also OK because Warrior IS a Character
	Character*	b = new Warrior();

	//This would NOT be ok because Character IS NOT a Warrior
	//(Although they ARE related, and W IS-C, the reverse is untrue)
	//Warrior*	c = new Character();

	//This would NOT be ok either because Cat IS NOT a Character
	//(They are not even related)
	//Character*	d = new Cat();

	a->sayHello("students");
	b->sayHello("students");

//error: delete called on non-final 'Warrior' that has virtual functions but non-virtual destructor [-Werror,-Wdelete-non-abstract-non-virtual-dtor]
	//delete a;  
	//delete b;

	return (0);
}
