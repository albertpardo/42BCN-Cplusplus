#ifndef SAMPLE_CLASS02_HPP
# define SAMPLE_CLASS02_HPP

#include <iostream>

class	Sample
{
	public:
		Sample( void );
		Sample( int const n);
		Sample( Sample const & src);
		~Sample( void );

		Sample &	operator=( Sample const & src);

		int	getFoo( void ) const;

	private:
		int	_foo;
};

std::ostream &	operator<<(std::ostream & o, Sample const & i );
#endif
