class	Quadruped //Can access name, run() and legs
{
	private:
		stdi::string	name; //Onlu accessible from a Quadruped object

	protected:
		Leg				leggs[4]; //Accesible from a Quadruped or derived object

	public:
		void			run(); //Accesible from wherever
};

class	Dog : public Quadruped //Can access run() and legs
{

};

int	main()  //Can only acces run()
{

}
