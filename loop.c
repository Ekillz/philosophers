/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:58:11 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/19 15:18:51 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rest(bool *rest)
{
	*rest = true;
	usleep(REST_T * SECOND);
	*rest = false;
}

int		think(t_env *e, pthread_mutex_t *g_pain)
{
	int nb;
	int t0;
	int t1;

	t0 = -1;
	t1 = -1;
	if (e->nb == 0)
		nb = 6;
	else
		nb = e->nb - 1;
	t0 = pthread_mutex_trylock(&g_pain[e->nb]);
	t1 = pthread_mutex_trylock(&g_pain[nb]);
	if (t0 == 0)
		pthread_mutex_unlock(&g_pain[e->nb]);
	if (t1 == 0)
		pthread_mutex_unlock(&g_pain[nb]);
	if (t0 == 0 || t1 == 0)
	{
		e->is_think = true;
		usleep(THINK_T * SECOND);
		e->is_think = false;
		return (1);
	}
	return (0);
}

void	life_steal(t_env *e, int *dead)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (!e[i].is_eat)
			e[i].life--;
		if (e[i].life <= 0)
			*dead = e[i].nb;
		i++;
	}
}

int		func_test(t_graph *t)
{
	if (t->dead > -1)
	{
		draw_scene(t);
		usleep(SECOND);
		exit(0);
	}
	else if ((time(0) - t->time) < TIMEOUT)
	{
		usleep(SECOND);
		draw_scene(t);
		life_steal(t->e, &t->dead);
	}
	else
		mlx_string_put(t->mlx, t->win,
				450, 150, 0xffff00, "Now, it is time... To DAAAAAAAANCE!!!");
	return (0);
}
