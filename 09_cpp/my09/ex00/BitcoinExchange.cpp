/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:07:51 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/23 13:07:48 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include <sstream>
#include "BitcoinExchange.hpp"

#define ERR_OPEN_RATES "Error opening DB file."
#define ERR_EMPTY_DB "Error DB is empty."
#define ERR_NO_DATE_IN_DB "Error: Date no in DB."
#define ERR_PARSING_RATES "Error parsing exchange rates file."
#define ERR_FILE "Error with your input file"

#define DATE_FORMAT "%Y-%m-%d"

#define COMA ','
#define PIPE '|'
#define DASH '-'

#define MAX_VALUE 1000.0
#define MIN_VALUE 0.0

#define SET_LIMIT true

#define NEGATIVE_VALUE "Error: not a positive number => "
#define LARGE_VALUE "Error: too large number => " 
#define ERR_MAX_INT "Error in DB file :  MAX_INT => " 
#define BAD_IN "Error: bad input => "

/* --- Ortodox public functions --- */

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & oth )
{
	*this = oth;
}

BitcoinExchange & BitcoinExchange::operator=( const BitcoinExchange & oth )
{
	if (this != &oth)
	{
		this->_rates = oth._rates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (!this->_rates.empty())
		this->_rates.clear();
	if (this->_ratesFd.is_open())
		this->_ratesFd.close();
	if (this->_exchangesFd.is_open())
		this->_exchangesFd.close();
}

/* --- Public functions --- */
void	BitcoinExchange::loadRates(const std::string &fileRate)
{
	if (this->_ratesFd.is_open())
		this->_ratesFd.close();
	this->_ratesFd.open(fileRate.c_str());
	if (this->_ratesFd.fail() == true)
		throw std::runtime_error(ERR_OPEN_RATES);
	this->_putCsvToRates();
	this->_ratesFd.close();
	if (this->_rates.empty())
		throw std::runtime_error(ERR_PARSING_RATES);
}

void	BitcoinExchange::getExchange(const std::string &fileToExchange)
{
	if (this->_rates.empty())
		throw std::runtime_error(ERR_EMPTY_DB);
	if (this->_exchangesFd.is_open())
		this->_exchangesFd.close();
	this->_exchangesFd.open(fileToExchange.c_str());
	if (this->_exchangesFd.fail() == true)
		throw std::runtime_error(ERR_FILE);
	this->_putExchangeVals();
	this->_exchangesFd.close();
}

/* --- Private functions --- */

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
 * 	- if ('newDate' == 'date' ) set 'ans' with 'dateString'
 * 		else throw EXCEPTION
 */

void	BitcoinExchange::_dateToStructTmp(const std::string& dateString, struct tm &ans)
{
    char char1 = ' ';
    char char2 = ' ';
    std::istringstream ss(dateString);   // dateString to chars buffer

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
		{
			ans = date;
			return;
		}
	}
	throw std::invalid_argument(BAD_IN);
}

/*
 * Converts string 'str' to float 'fvalue' 
 * if 'setLimit' is true checks that 'str' in [0, MAX_VALUE]
 * else checks that 'str' in [0, MAX_INT]
 * else
 * 		throw EXCEPTION
 */

void	BitcoinExchange::_strValToFVal(std::string str, float &fvalue, bool setLimit)
{
	double value;
	char *pRestStr = NULL;

	value = std::strtod(str.c_str(), &pRestStr);
	if (!*pRestStr)
	{
		if (value >= MIN_VALUE && ((setLimit && value <= MAX_VALUE) || \
					(!setLimit && value <= std::numeric_limits<int>::max())))
		{
			fvalue = static_cast<float>(value);
			return;
		}
		else if (value < MIN_VALUE)
			throw std::invalid_argument(NEGATIVE_VALUE);
		else if (!setLimit && value > std::numeric_limits<int>::max())
			throw std::invalid_argument(ERR_MAX_INT);
		else
			throw std::invalid_argument(LARGE_VALUE);
	}
	else
		throw std::invalid_argument(BAD_IN);
}

/*
 * Converts string 'line' that contains a 'date' and a 'value' to a tuple with 'date' and float value
 * 'setLimit' is used for check value in [0, MAX_VALUE] or in [0, MAX_INT]
 * 'toFind' is th separator char between  'date' and 'value' 
 *
 * 	throw EXCEPTION for no expected options 
 */

void	BitcoinExchange::_getDateVal(std::string &line, char const toFind, \
			std::pair<std::tm, float> &dateVal, bool setLimit)
{
    std::string date;
    std::string value;
	struct tm	tm_date;
	float		fvalue;

    std::size_t found = line.find(toFind);
    if (found!=std::string::npos)
    {
        date = line.substr(0, found);
        value = line.substr(found + 1);
		try
		{
			this->_dateToStructTmp(date, tm_date);
			this->_strValToFVal(value, fvalue, setLimit);
			dateVal.first = tm_date;
			dateVal.second = fvalue; 
		}
		catch(const std::exception & e)
		{
			throw std::invalid_argument(e.what() + line );
		}
    }
    else
    {
		throw std::invalid_argument(BAD_IN + line );
    }
}

/*
 *	Create a 'DB' in memory using container 'map'
 *	File descriptor 'this->_ratesFd' is used to acces to 'DB file'
 *
 * 	throw EXCEPTION for no expected options 
 */

void	BitcoinExchange::_putCsvToRates( void )
{
	std::string					line;
	std::pair<std::tm, float>	tmp;

	std::getline(this->_ratesFd, line, '\n');	
	if (line != "date,exchange_rate")
		throw std::runtime_error(ERR_OPEN_RATES);
	while(std::getline(this->_ratesFd, line, '\n'))
	{
		this->_getDateVal(line, COMA, tmp, !SET_LIMIT);
		this->_rates.insert(tmp);
	}
	if ((this->_ratesFd.bad() || !this->_ratesFd.eof()) && !this->_rates.empty()) 
	{
		this->_rates.clear();
		throw std::runtime_error(ERR_OPEN_RATES);
	}
}

/*
 *	 Put on screen the result of one exchangevalue 
 *
 * 	throw EXCEPTION for no expected options 
 */

void	BitcoinExchange::_doOneExchage(std::pair<std::tm, float> &dateVal)
{
	std::map<std::tm, float>::reverse_iterator rit;
	std::tm	date = dateVal.first;

	rit = this->_rates.rbegin();
	while (rit != this->_rates.rend() && date < rit->first)
		rit++;
	if (rit != this->_rates.rend())
	{
		std::cout << date.tm_year + 1900 << "-" ;
		if (date.tm_mon >= 0 && date.tm_mon < 10)
		   std::cout << "0"	;
		std::cout << date.tm_mon + 1 << "-";
		if (date.tm_mday >= 0 && date.tm_mday < 10)
		   std::cout << "0"	;
		std::cout << date.tm_mday << " => " << dateVal.second << " = " \
		   	<< dateVal.second * rit->second << std::endl;
	}
	else
		throw std::runtime_error(ERR_NO_DATE_IN_DB);
}

/*
 * Put on screen the exchanges valus given with a file with 
 * 		file desriptor 'this->_exchangesFd'
 * 		
 * 	throw EXCEPTION for no expected options 
 */

void	BitcoinExchange::_putExchangeVals( void )
{
	std::string					line;
	std::pair<std::tm, float>	tmp;

	std::getline(this->_exchangesFd, line, '\n');
	if (line != "date | value")
		throw std::runtime_error(ERR_FILE);

	while(std::getline(this->_exchangesFd, line, '\n'))
	{	
		try
		{
			this->_getDateVal(line, PIPE, tmp, SET_LIMIT);
			this->_doOneExchage(tmp);
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
	if (this->_exchangesFd.bad() || !this->_exchangesFd.eof()) 
	{
		throw std::runtime_error(ERR_FILE);
	}
}

/*  Extra functionts */

/*  overload operator "<" with std::tm for use in:
 *  	std::map<std::tm, float>
 *
 *  Because 'map' has not overload this operator for use with std::tm
 */

bool operator<(const std::tm& t1, const std::tm& t2)
{
	return (t1.tm_year < t2.tm_year || \
			(t1.tm_year == t2.tm_year && (t1.tm_mon < t2.tm_mon || \
			 (t1.tm_mon == t2.tm_mon && t1.tm_mday < t2.tm_mday))));
}


