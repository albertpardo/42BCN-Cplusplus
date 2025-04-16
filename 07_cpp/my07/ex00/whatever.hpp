/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:04:25 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/15 09:04:29 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/* C++ Function Template
 * https://www.programiz.com/cpp-programming/function-template
 *
 * 'typename'  is used
 *
 * https://cplusplus.com/doc/oldtutorial/templates/
 *
 * keyword 'class'  or the keyword 'typename'. 
 * Its use is indistinct, since both expressions have exactly the same meaning
 *    and behave exactly the same way.
 *
 * Officially, what is typename for?
 * https://stackoverflow.com/questions/1600936/officially-what-is-typename-for
 *
 * Where and why do I have to put the "template" and "typename" keywords?
 * https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
 *
 * A Description of the C++ typename keyword
 * https://pages.cs.wisc.edu/~driscoll/typename.html
 * Prefers use 'typename' vs 'class'
 */

template <typename T>
void	swap(T & value1, T & value2)
{
	T	tmp = value1;

	value1 = value2;
	value2 = tmp;
}

template <typename T>
const T	min(const T & value1, const T & value2)
{
	return ( value1 < value2 ? value1 : value2 );
}

template <typename T>
const T max(const T & value1, const T & value2)
{
	return ( value1 > value2 ? value1 : value2 );
}

#endif
