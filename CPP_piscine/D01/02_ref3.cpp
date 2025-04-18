#include <iostream>
#include <string>

class	Student
{
	private:
		std::string	_login;

	public:
		Student(std::string login) : _login(login)
		{
		}

		~Student()
		{
			std::cout << "Student " << this->_login << " is died" << std::endl;
		}

		std::string&	getLoginRef()
		{
			return this->_login;
		}
		
		std::string const &	getLoginRefConst() const
		{
			return this->_login;
		}

		std::string*	getLoginPtr()
		{
			return &(this->_login);
		}

		std::string const *	getLoginPtrConst() const
		{
			return &(this->_login);
		}
};

int		main()
{
	Student			bob = Student("bfubar");
	Student const	jim	= Student("jfubar");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	bob.getLoginRef() = "bobyfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bobyfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	return (0); // bob is destroyed
}
