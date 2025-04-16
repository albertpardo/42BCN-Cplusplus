#include <cstdlib>
#include <iostream>
#include <sstream>

#define MAX_VALUE 1000.0
#define MIN_VALUE 0.0

#define NEGATIVE_VALUE "Error: not a positive number: "
#define LARGE_VALUE "Error: too large number: " 
#define BAD_IN "Error: bad input => "

static void detectBadValue(std::string str)
{
	double value;
	char *pRestStr = NULL;

	value = std::strtod(str.c_str(), &pRestStr);
	if (!*pRestStr)
	{
		if (value >= MIN_VALUE && value <= MAX_VALUE)
			return;
		else if ( value < MIN_VALUE)
			throw std::invalid_argument(NEGATIVE_VALUE);
		else
			throw std::invalid_argument(LARGE_VALUE);
	}
	else
		throw std::invalid_argument(BAD_IN);
}

static void test(std::string str)
{
	std::cout << "\"" << str << "\" -> ";
	try
	{
		detectBadValue(str);
		std::cout << "OK!" << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << str << std::endl;
	}
}

int	main( void )
{
	test("5");
	test("+5");
	test("0");
	test("0.0");
	test("1000");
	test("1000.0");
	test("-5");
	test("--5");
	test("6-5");
	test("6a");
	test("6a 8");
	test("6 8");
	test("a6");
	test("1000.01");
	return(0);
}
