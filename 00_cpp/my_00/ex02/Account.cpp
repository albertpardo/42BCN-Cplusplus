/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:57:52 by apardo-m          #+#    #+#             */
/*   Updated: 2024/06/19 14:01:02 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

// Private

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
}

/*
 * Prints actual date and time in format [YYYYMMDD_HHMMSS]
 *
 * Where :
 * 	YYYY actual year
 * 	MM	actual Month
 * 	DD	actaul Day
 * 	HH 	actual Hour
 * 	MM	actual Minutes
 * 	SS	actual Seconds
 *
 * links :
 * https://www.programiz.com/cpp-programming/library-function/ctime/localtime
 * Struct tm :
 * https://cplusplus.com/reference/ctime/tm/
 */

void	Account::_displayTimestamp( void )
{
	std::time_t now;
    std::tm* tm_inf;
	int	num;
   
	std::time(&now);
    tm_inf = std::localtime(&now);
    std::cout << "[" << 1900 + tm_inf->tm_year ;
	num = 1 + tm_inf->tm_mon;
	if (num < 10)
		std::cout << "0";
	std::cout << num;
	num =  tm_inf->tm_mday;
	if (num < 10)
		std::cout << "0";
	std::cout << num << "_";
  	num = tm_inf->tm_hour;
	if (num < 10)
		std::cout << "0";
	std::cout << num;
	num = tm_inf->tm_min;
	if (num < 10)
		std::cout << "0";
	std::cout << num;
	num = tm_inf->tm_sec;
	if (num < 10)
		std::cout << "0";
	std::cout << num << "] ";
}

// Public	

int		Account::getNbAccounts( void )
{
	return ( Account::_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return ( Account::_totalAmount );
}

int		Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits );
}

int		Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals );
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_nbAccounts++;
	this->_amount+= initial_deposit;
	this->_totalAmount+= initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount+= deposit;
	this->_totalAmount+= deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > Account::checkAmount())
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount-= withdrawal;
	this->_totalAmount-= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
