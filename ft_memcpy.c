/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:24:04 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/05 13:21:23 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*original;

	original = dst;
	while (n)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		n--;
	}
	return (original);
}
