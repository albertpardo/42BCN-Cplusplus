void	dump_32bits_integer( int const n);
void	dump_64bits_double( double const z);

int		main( void )
{
	int 	a = 42;			/* Reference value */

	double	b = a;			/* Implicit conversion cast */
	double	c = (double) a;	/* Explicit conversion cast */

	double	d = a;			/* Implicit promotion -> Ok */
	int		e = d;			/* Implicit demotion  -> Hardzous! (You can use compiler falg to avoid implicit cast  problems -Wno (avoid precision problems) */
	int		f = (int) d;	/* Explicit demotion  -> Ok, you're in charge */

	dump_32bits_integer( a );

	dump_64bits_double( b );
	dump_64bits_double( c );

	dump_64bits_double( d );
	dump_32bits_integer( e );
	dump_32bits_integer( f );

	return (0);
}
