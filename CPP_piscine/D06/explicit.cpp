#include <iostream>

class A {};
class B {};

class C
{
	public:
		C( A const & _)
		{
			return ;
		}
		explicit C( B const & _)
		{
			return;
		}
};

void	f( C const & _ )
{
	return;
}

int	main( void )
{
	f(A());		//Implicit conversion Ok  ( A to C)
	f(B());		//Implicit conversion NOT OK, constructor is explicit

	return (0);
}
