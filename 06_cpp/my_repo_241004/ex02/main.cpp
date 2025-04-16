
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
 * dynamic casting 
 * https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/
 * dynamic casting is mainly used for safe downcasting (from father to son) at run time
 *
 * Examples:
 * https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/
 */

Base * generate(void)
{
	int	i;
	
	std::srand(std::time(NULL));
	i = std::rand() % 3;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	return (new C());
}

/*
 * Dynamic Casts with Pointers
 * https://www.ibm.com/docs/en/i/7.5?topic=operator-dynamic-casts-pointers
 */

void identify(Base* p)
{
	std::cout << "identify(Base* p) -> Class Object: ";
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Class Object No detected" << std::endl;
}

/*
 * Base& p  is a Memory address to A, B or C
 * dynamic_cast<A &>(p) generates "std::bad_cast" exception when 'p' is B or C 
 *
 * Dynamic Casts with References
 * https://www.ibm.com/docs/en/i/7.5?topic=operator-dynamic-casts-references
 */
void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "identify(Base& p) -> Class Object: A" << std::endl;
	}
	catch (std::exception& e) {}

	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "identify(Base& p) -> Class Object: B" << std::endl;
	}
	catch (std::exception& e) {}

	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "identify(Base& p) -> Class Object: C" << std::endl;
	}
	catch (std::exception& e) {}
}

/*
 * Alternative way
 * Catch exception for Base& NULL
 */

/*
void identify(Base& p)
{
	std::cout << "identify(Base& p) -> Class Object: ";
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception& e)
	{
		try
		{
			(void) dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception& e)
		{
			try
			{
				(void) dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}
*/

int	main( void )
{
	Base	*p;

	p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}
