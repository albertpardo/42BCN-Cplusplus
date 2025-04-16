/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:08:44 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/15 10:47:44 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/*
 * Containers
 * https://cplusplus.com/reference/stl/
 *
 * Use an 'iterator' to move inside 'container'
 * C++98 valid containers : <deque> ,<list>, <map>, <queue>, <set>, <stack>, <vector>
 *
 * <algorithm>
 * 	https://cplusplus.com/reference/algorithm/
 * 	<algorithm> defines a collection of functions especially designed to be used 
 * 		on ranges of elements.
 * 	A range is any sequence of objects that can be accessed through iterators 
 * 		or pointers
 *
 * Why can templates only be implemented in the header file?
 * https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
 *
 * 'tpp' files  can be include at the end of 'hpp' file
 */

template <typename T>
void	easyfind(const T &t, const int n);

# include "easyfind.tpp"

#endif
