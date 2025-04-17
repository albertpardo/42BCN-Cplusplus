#include <iostream>
#include "Sample.Class00.hpp"

Sample::Sample( void )
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample( void )
{
	std::cout << "Destductor called" << std::endl;
	return;
}

void	Sample::bar( char const c) const
{
	std::cout << "Member function bar called whith char overload: " << c << std::endl;
	return;
}

void	Sample::bar( int const n) const
{
	std::cout << "Member function bar called whith int overload: " << n << std::endl;
	return;
}

void	Sample::bar( float const z) const
{
	std::cout << "Member function bar called whith float overload: " << z << std::endl;
	return;
}

void	Sample::bar( Sample const & i) const
{
	( void ) i;
	std::cout << "Member function bar called whith Sample overload (but not used)" << std::endl;
	return;
}
