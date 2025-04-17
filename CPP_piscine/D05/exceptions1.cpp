#include <stdexcept>

void	test1( void )
{
	try
	{
		//Do some stuff here
		if (/* there's an error */)
		{
			throw std::exception();
		}
		else
		{
			//Do some more stuff
		}
	}
	catch (std::exception e)
	{
		//Handle the error here
	}
}

void	test2( void )
{
		//Do some stuff here
		if (/* there's an error */)
		{
			throw std::exception();
		}
		else
		{
			//Do some more stuff
		}
}

void	test3( void )
{
	try
	{
		test2();
	}
	catch (std::exception& e)
	{
		//Handle the error here
	}
}

void	test4( void )
{
	class PEBKACException : puclic std::exception
	{
		puclic:
			virtual	const char* what() const throw()
			{
				return ("Problem exists between keyboard and chair");
			}
	};

	try
	{
		test3();
	}
	catch (PEBKACException& e)
	{
		// Specifir catch
		//Handle the fact the the user is an idiot
	}
	catch (std::exception& e)
	{
		// Generic catch
		//Handle other exceptions that are like std::exception
	}
}
