/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:11:29 by apardo-m          #+#    #+#             */
/*   Updated: 2024/10/12 18:24:15 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cctype>
#include <stack>
#include <sstream>
#include "RPN.hpp"

/*
 * How to split a string in C/C++, Python and Java?
 *   https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
 */

#define ERR_NO_VALID_VALUE_OPER "Error: No valid value or operand"
#define ERR_SIZE "Error: No valid argument : "
#define ERR_IN_ISS "Error: problems reading arguments."
#define ERR_MORE_ONE "Error: No valid RPN format"
#define ERR_STACK "Error : No enougth values for RPN operation."
#define ERR_DIV_CERO "Error : Division by 0."

/*
 * 'op' : Expected operators : + , - , * , /
 * 	for other values in 'op' do nothing
 */ 

static void	doOperation(char op, std::stack<int> &stackNum)
{
	int n1;
	int	n2;

	if (stackNum.size() > 1)
	{
		n1 = stackNum.top();
		stackNum.pop();
		n2 = stackNum.top();
		stackNum.pop();
		if (op == '+')
			stackNum.push(n2 + n1);
		else if (op == '-')
			stackNum.push(n2 - n1);
		else if (op == '*')
			stackNum.push(n2 * n1);
		else if (op == '/')
		{	
			if (n1 != 0)
				stackNum.push(n2 / n1);
			else
				throw std::runtime_error(ERR_DIV_CERO);
		}
	}
	else
		throw std::runtime_error(ERR_STACK);
}

void	execRpn(std::string  str)
{
	std::stack<int>		stackNum;
	std::istringstream	iss(str);
	std::string			arg;

	while (iss >> arg)
	{
		if (arg.size() == 1)
		{
			if (std::isdigit(static_cast<unsigned char>(arg[0]))) 
				stackNum.push(std::atoi(arg.c_str()));
			else if (arg[0] == '+' || arg[0] == '-' || arg[0] == '*' || arg[0] == '/')
				doOperation(arg[0], stackNum);
			else
				throw std::runtime_error(ERR_NO_VALID_VALUE_OPER);
		}
		else
			throw std::runtime_error(ERR_SIZE + arg);
	}	
	if (iss.bad() || !iss.eof())
		throw std::runtime_error(ERR_IN_ISS);
	if (stackNum.size() != 1)
		throw std::runtime_error(ERR_MORE_ONE);
	std::cout << stackNum.top() << std::endl;
}
