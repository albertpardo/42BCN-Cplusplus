#include <string>

class 	Animal
{
	private:
		int		_numberOfLegs;

	public:
		Animal();
		Animal( Animal const & );
		Animal& operator=( Animal const & );
		~Animal();

		void	run( int distance );
		void	call();
		void	eat( std::string const & what );
		void	walk( int distance );

};

class	Otter : public Animal
{
	public:
		Otter();
		Otter( Otter const &);
		Otter& operator=( Otter const &);
		~Otter();
};

class	Cat : public Animal
{
	public:
		Cat();
		Cat( Cat const &);
		Cat& operator=( Cat const &);
		~Cat();

		void	scornSomeone(std::string const & target);
};

class	Pony : public Animal
{
	public:
		Pony();
		Pony( Pony const & );
		Pony& opertor=( Pony const & );
		~Pony();

		void	doMagic(std::string const & target );
};
