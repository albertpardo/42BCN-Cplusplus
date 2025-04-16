/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:08:56 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/11 14:45:55 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>

bool			operator<(const std::tm& t1, const std::tm& t2);
bool	tm1LessTm2(const std::tm& t1, const std::tm& t2);

class	BitcoinExchange
{
	private:
		std::map<std::tm, float>	_rates;
		std::ifstream				_ratesFd;
		std::ifstream				_exchangesFd;

		void	_dateToStructTmp(const std::string& dateString, struct tm &ans);
		void	_strValToFVal(std::string str, float &fvalue, bool setLimit);
		void	_getDateVal(std::string &line, char const toFind, \
					std::pair<std::tm, float> &dateVal, bool setLimit);
		void	_putCsvToRates( void );
		void	_doOneExchage(std::pair<std::tm, float> &dateVal);
		void	_putExchangeVals( void );

	public:
		BitcoinExchange(void);
		BitcoinExchange( const BitcoinExchange & oth );
		BitcoinExchange & operator=( const BitcoinExchange & oth );
		~BitcoinExchange(void);

		void	loadRates(const std::string &fileRate);
		void	getExchange(const std::string &fileToExchange);
};

#endif
