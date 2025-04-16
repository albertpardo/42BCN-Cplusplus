/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:05:09 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/16 11:31:19 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

/*
 *	'iter' doesn't check 'size' (Out of bonds array ERROR if 'size' > real array size)
 */
template <typename T>
void	iter(T * arr, unsigned int size, void (*func)(T &))
{
	unsigned int i;

	if (arr == NULL || func == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		func(arr[i]);
		i++;
	}
}

#endif
