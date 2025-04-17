int		main( void )
{
	int 		a = 42;					/* Reference value */

	int const	*b = &a;				/* Implicit conversion cast */
	int const	*c = (int const *) &a;	/* Explicit conversion cast */

	int const	*d = &a;				/* Implicit promotion -> Ok */
	int			*e = d;					/* Implicit demotion -> Hell no*/
	int			*f = (int *) d;			/* Explicit demotion -> Ok, I obey */

	return (0);
}
