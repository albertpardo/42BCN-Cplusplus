#include <iostream>

int		main( void )
{
	int 	a = 42;							/* Reference value */

	int	const	*b = &a;						/* Implicit promotion -> Ok */
	int			*c = b;						/* Implicit demotion -> Hell No ! */
	int			*d = const_cast<int *>(b);	/* Implicit demotion -> Ok , I obey */
	
	std::cout << "a = " << a << std::endl;
	std::cout << "*b = " << *b << std::endl;
	std::cout << "*c = " << *c << std::endl;
	std::cout << "*d = " << *d << std::endl;

	return (0);
}
