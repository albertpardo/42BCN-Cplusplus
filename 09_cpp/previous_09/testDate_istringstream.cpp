#include <iostream>
#include <ctime>
#include <sstream>

#define DATE_FORMAT "%Y-%m-%d"
#define DASH '-'

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

static void putResultIsVAlidDate(std::string const & date)
{
	std::cout << std::boolalpha;	
		std::cout <<"\t" << date << " is valid ? ";
	try
	{
		checkDate(date);
		std::cout <<"OK" << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << date << std::endl;
	}
	
	std::cout << std::noboolalpha;	
}

int main()
{
	std::string str;

	std::cout << "/* --- TESTS with 'testDate_stringstream.cpp' --- */" << std::endl;
	putResultIsVAlidDate("2012-10-32");
	putResultIsVAlidDate("2012-10-10");
	putResultIsVAlidDate("2012-02-29");
	putResultIsVAlidDate("2024-02-32");
	putResultIsVAlidDate("2024-09-30");
	putResultIsVAlidDate("2024-01-00");
	putResultIsVAlidDate("2012-42-15");
	putResultIsVAlidDate("2024-1-1");
	putResultIsVAlidDate("2024-a-1");
	putResultIsVAlidDate("2024-9- PEPE");
	putResultIsVAlidDate("2024   -  5  -1"); //Se da por bueno. Pero hay que guardarlo arreglado ¿Lo trato como error?
	putResultIsVAlidDate("3028 \t -  9  -  2"); //Se da por bueno. Pero hay que guardarlo arreglado ¿Lo trato como error?
	putResultIsVAlidDate("2024a1a1");
	putResultIsVAlidDate("2024aib1a1");
	putResultIsVAlidDate("2012,10/10");
	putResultIsVAlidDate("2011/10/10");
	putResultIsVAlidDate("2022");
	putResultIsVAlidDate("2022--");
	std::cout << "\nNext dates are checked in rigth:" << std::endl;
	putResultIsVAlidDate("2024-02-30");
	putResultIsVAlidDate("2023-02-29");
	putResultIsVAlidDate("2024-02-31");
	putResultIsVAlidDate("2024-09-31");

	return (0);
}

