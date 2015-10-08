/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:58:11 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/08 15:15:09 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	think(t_env *e)
{
	e->is_think = true;
	usleep(THINK_T * SECOND);
	e->is_think = false;
}

void	life_steal(t_env *e)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (!e[i].is_eat)
			e[i].life--;
		i++;
	}
}

int func_test(t_graph *t)
{
	draw_scene(t);
	if ((time(0) - t->time) > TIMEOUT)
		exit(0);
	usleep(SECOND);
	life_steal(t->e);
	return (0);
}

void	del_ressources(pthread_mutex_t *g_pain, pthread_t *philo)
{
	int i;

	i = 0;
	while (i < 7)
	{
		pthread_detach(philo[i]);
		pthread_mutex_destroy(&g_pain[i]);
		i++;
	}

}
