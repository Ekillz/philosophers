/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 15:35:03 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/08 15:35:23 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char        *ft_itoa(int n)
{
	char    *ret;
	int     size;
	int     conv;
	int     neg;

	size = 1;
	neg = ((n < 0) ? 1 : 0);
	if (neg && size++)
		n *= -1;
	conv = n;
	while ((n = n / 10))
		size++;
	ret = malloc(sizeof(char) * size);
	while (size--)
	{
		ret[size] = conv % 10 + '0';
		conv /= 10;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
