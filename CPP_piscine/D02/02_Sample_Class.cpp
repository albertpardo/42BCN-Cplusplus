#include "Sample.Class02.hpp"

Sample::Sample( void ) : _foo(0)
{
	std::cout << "Default Constructor Called" << std::endl;
	return;
}

Sample::Sample( int const n) : _foo(n)
{
	std::cout << "Parametric Constructor Called" << std::endl;
	return;
}

Sample::Sample( Sample const & src)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = src;
	return;
}


Sample::~Sample( void )
{
	std::cout << "Destructor Called" << std::endl;
	return;
}

Sample &	Sample::operator=( Sample const & src)
{
	std::cout << "Assignament operator Called" << std::endl;
	if ( this != &src)
		this->_foo = src.getFoo();
	return ( *this );
}

int	Sample::getFoo( void ) const
{
	return ( this->_foo );
}

std::ostream &	operator<<(std::ostream & o, Sample const & i )
{
	o << "The value of _foo is : " << i.getFoo();
	return (o);
}
