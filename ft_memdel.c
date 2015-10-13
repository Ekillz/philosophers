/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:18:08 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/13 18:27:02 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		if (*ap != NULL)
			free(*ap);
		*ap = NULL;
	}
}
