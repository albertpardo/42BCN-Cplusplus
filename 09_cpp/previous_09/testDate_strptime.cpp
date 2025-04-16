/*
 * Adapted from :
 * C++ check if a date is valid
 * https://stackoverflow.com/questions/9436697/c-check-if-a-date-is-valid
 *
 * PROBLEMS
 * - 1 : Don't check extra day in february for leap year  (año bisiesto)
 * - 2 : Don't check rigth limit month (limit 300 or 31?) 
 *
 */


#include <iostream>
#include <time.h>

#define DATE_FORMAT "%Y-%m-%d"

static bool isValidDate(char const *date)
{
	struct tm tm;

	if (strptime(date, DATE_FORMAT, &tm))
		return (true);
	return (false);
}

static void putResultIsVAlidDate( char const *date)
{
	std::cout << std::boolalpha;	
	std::cout <<"\t" << date << " is valid ? " << isValidDate(date) << std::endl;
	std::cout << std::noboolalpha;	
}

int main( void)
{
	std::cout << "/* --- TESTS with 'testDate_strptime.cpp' --- */" << isValidDate(date) << std::endl;
	putResultIsVAlidDate("2012-10-32");
	putResultIsVAlidDate("2012-10-10");
	putResultIsVAlidDate("2012-02-29");
	putResultIsVAlidDate("2024-02-32");
	putResultIsVAlidDate("2024-09-30");
	putResultIsVAlidDate("2024-01-00");
	putResultIsVAlidDate("2012-42-15");
	std::cout << "\nNext dates are bad checked:" << std::endl;
	putResultIsVAlidDate("2024-02-30");
	putResultIsVAlidDate("2023-02-29");
	putResultIsVAlidDate("2024-02-31");
	putResultIsVAlidDate("2024-09-31");

	return (0);
}
