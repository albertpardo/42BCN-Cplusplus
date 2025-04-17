#include <iostream>
#include <typeinfo>
#include <exception>

class Parent
{
	public:
		virtual ~Parent( void ) {};  //Virtual for use dynamic cast
};

class Child1 : public Parent {};
class Child2 : public Parent {};

class Unrelated {};

int	main( void )
{
	Child1	a;								// Reference value
	Parent	*b = &a;						// Implicit upcast -> Ok

	//Explicit downcast -> Suspens ....
	Child1	*c = dynamic_cast<Child1 *>(b);
	if (c == NULL)
	{
		std::cout << "Conversion is NOT Ok" << std::endl;
	}
	else
	{
		std::cout << "Conversion is Ok" << std::endl;
	}

	//Explicit downcast -> Suspens ....
	try
	{
		Child2	&d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion is Ok" << std::endl;
	}
	// see : https://en.cppreference.com/w/cpp/types/bad_cast
	catch (std::bad_cast &bc)
	{
		std::cout << "Conversion is NOT Ok: " << bc.what() << std::endl;
		return (0);
	}
	return (0);
}
