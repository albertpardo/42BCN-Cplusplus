#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

#define DATE_FORMAT "%Y-%m-%d"

#define COMA ','
#define PIPE '|'
#define DASH '-'

#define MAX_VALUE 1000.0
#define MIN_VALUE 0.0

#define NEGATIVE_VALUE "Error: not a positive number => "
#define LARGE_VALUE "Error: too large number => " 
#define BAD_IN "Error: bad input => "

/*
 * <ctime> : struct tm , mktime
 * <sstream> : istringstream
 *
 * 'tm' struct time data
 * 'mktime' makes a automatic ajust for OFF-RANGE values to next right value
 *
 * Process:
 * 	- 'dateString' is converted to 'tm date'
 * 	- 'tm newDate' is a copy ot 'tm date'
 * 	- 'mktime' ajust OFF-RANGE values
 * 	- if ('newDate' == 'date' ) return TRUE
 * 		else return FALSE
 *
 */

static bool isValidDate(const std::string& dateString)
{
    char char1 = ' ';
    char char2 = ' ';
    std::istringstream ss(dateString);   // Pone dateString en un buffer de chars

    struct tm date = {};    // All struct vars set to 0
    struct tm newDate = {};

    ss >> date.tm_year >> char1 >> date.tm_mon >> char2 >> date.tm_mday;
	if (char1 == DASH && char2 == DASH)
	{
		date.tm_year -= 1900; 
		date.tm_mon -= 1;
		date.tm_hour = 1;
		newDate = date;
		mktime(&newDate);
		if ( date.tm_year == newDate.tm_year && date.tm_mon == newDate.tm_mon && \
			date.tm_mday == newDate.tm_mday )
		return true;
	}
	return false;
}

static void	checkDate(std::string const & date)
{
	if (!isValidDate(date))
		throw std::invalid_argument(BAD_IN);
}

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

static void test(std::string const &str , char const toFind)
{
    std::string date;
    std::string value;

    std::size_t found = str.find(toFind);
    if (found!=std::string::npos)
    {
        date = str.substr(0, found);
        value = str.substr(found + 1);
        std::cout << "\"" << str  << "\" -> ";
		try
		{
			checkDate(date);
			detectBadValue(value);
			std::cout << "OK!" << std::endl;
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << str << std::endl;
		}
    }
    else
    {
        std::cout << "\"" << str  << "\" -> " << BAD_IN << str << std::endl;
    }
}

int main(void)
{
    test("2010-04-04,0", COMA);
    test("2010-04-04,10000", COMA);
    test(",", COMA);
    test("", COMA);
    test(",,,,,,,,,", COMA);
    test("", PIPE);
    test("2010-04-04|0", PIPE);
    test("2010-04-04", PIPE);
	std::cout << "\n -- Test parte subject -- " << std::endl;
    test("2011-01-09 | 1", PIPE);
    test("2012-01-11 | -1", PIPE);
    test("2001-42-42", PIPE);
    test("2012-01-11 | 1", PIPE);
    test("2012-01-11 | 2147483648", PIPE);
	std::cout << "\n -- Test extra subject -- " << std::endl;
    test("2012-01-43 | 2147483648", PIPE);
    return (0);
}
