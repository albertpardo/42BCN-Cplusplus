#include <iostream>

class Parent		{};
class Child1 : public Parent {};
class Child2 : public Parent {};

class Unrelated {};

int	main( void )
{
	Child1	a;								// Reference value

	Parent	*b = &a;						// Implicit upcast -> Ok
	Child1	*c = b;							// Implicit downcast -> Hell no !!
	Child2	*d = static_cast<Child2 *>(b);	// Expicit downcast -> Ok , I obey

	Unrelated *e = static_cast<Unrelated *>(&a)	// Expicit convertion -> No !

	return (0);
}
