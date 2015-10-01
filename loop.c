/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:58:11 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/01 13:02:37 by emammadz         ###   ########.fr       */
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

void	show_info(t_env *e)
{
	int i;
	//int t;
	i = 0;

	//t = time(0);
	//if ((time(0) - t) > TIMEOUT)
	while (1)
	{
		if (i == 7)
		{
			i = 0;
			write(1, "\n", 1);
			usleep(SECOND);
			life_steal(e);
		}
		if (e[i].life <= 0)
			break;
		if (e[i].is_eat)
			printf("philo[%d] is eating: life = %d\n", e[i].nb, e[i].life);
		else if (e[i].is_rest)
			printf("philo[%d] is resting: life = %d\n", e[i].nb, e[i].life);
		else
			printf("philo[%d] is thinking: life = %d\n", e[i].nb, e[i].life);
		write(1, "\n", 1);
		i++;
	}
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
