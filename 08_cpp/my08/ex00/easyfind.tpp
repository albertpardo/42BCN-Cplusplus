/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:08:44 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/15 09:08:47 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>
# include <algorithm>
# include "easyfind.hpp"

/*
 * exception
 * https://cplusplus.com/reference/exception/exception/
 *
 * 'std::invalid_argument' is used when 'n' is not inside 't' range
 */	

template <typename T>
void	easyfind(const T &t, const int n)
{
	if (std::find(t.begin(), t.end(), n) != t.end())
		std::cout << "Element found" << std::endl;
	else
		throw std::invalid_argument("Element not found");
}
#endif

