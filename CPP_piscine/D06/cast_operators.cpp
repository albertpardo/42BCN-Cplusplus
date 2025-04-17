#include <iostream>

class Foo
{
	public:
		Foo (float const v ) : _v( v ){}

		float	getV( void )
		{
			return (this->_v);
		}

		operator float()
		{
			return (this->_v);
		}
		operator int()
		{
			return (static_cast<int>(this->_v));
		}

	private:
		float	_v;
};

int	main( void )
{
	Foo		a(420.024f);
	float	b = a;
	int		c = a;

	std::cout << "a = " << a.getV() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	return (0);
}
