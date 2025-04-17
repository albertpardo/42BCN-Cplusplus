int	main( void )
{
	int		a = 42;					// Reference value

	double	b = a;					// Implicit promotion -> Ok
	int		c = b;					// Implicit demotion  -> Hell no !
	int		d = static_cast<int>(b);// Implicit demotion -> Ok, I obey
	return (0);
}
