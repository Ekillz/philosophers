/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 14:35:50 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/19 14:52:18 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	choose_baguette_color(int *color, int index, t_env *e)
{
	int nb;

	nb = index - 1;
	index == 0 ? (nb = 6) : 0;
	if (e[index].is_eat || e[nb].is_eat)
		*color = 0xff0000;
	else
		*color = 0x00ff00;
}

void	get_baguette_coord(t_graph *t)
{
	t->stickx = malloc(sizeof(int) * 7);
	t->sticky = malloc(sizeof(int) * 7);
	t->stickx[0] = 667;
	t->sticky[0] = 422;
	t->stickx[1] = 537;
	t->sticky[1] = 331;
	t->stickx[2] = 381;
	t->sticky[2] = 358;
	t->stickx[3] = 326;
	t->sticky[3] = 507;
	t->stickx[4] = 393;
	t->sticky[4] = 651;
	t->stickx[5] = 532;
	t->sticky[5] = 682;
	t->stickx[6] = 653;
	t->sticky[6] = 580;
}

void	get_philo_lives(t_graph *t)
{
	int i;
	int e;

	e = 0;
	t->lifes = malloc(sizeof(int*) * 7);
	while (e < 7)
	{
		i = 0;
		while (i < 7)
		{
			if (t->e[i].nb == e)
			{
				t->lifes[e] = &t->e[i].life;
				e++;
				break ;
			}
			i++;
		}
	}
	t->lifes[e] = 0;
}
