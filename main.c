/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:22:12 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/01 13:38:44 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

pthread_mutex_t		g_lock; // mettre dans struct //
pthread_mutex_t		g_pain[7];
int					count;


static void		rest(t_env *e)
{
	e->is_rest = true;
	usleep(REST_T * SECOND);
	e->is_rest = false;
}

static int		eat(t_env *e)
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
	if (t0 == 0 && t1 == 0)
	{
		e->is_eat = true;
		e->life = MAX_LIFE;
		usleep(EAT_T * SECOND);
		pthread_mutex_unlock(&g_pain[e->nb]);
		pthread_mutex_unlock(&g_pain[nb]);
		e->is_eat = false;
		return (1);
	}
	if (t0 == 0)
		pthread_mutex_unlock(&g_pain[e->nb]);
	else if (t1 == 0)
		pthread_mutex_unlock(&g_pain[nb]);
	return (0);
}

static void		*mrPhilo(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	pthread_mutex_trylock(&g_lock);
	count++;
	e->nb = count;
	pthread_mutex_unlock(&g_lock);
	while (e->life > 0)
	{
		if (eat(e))
			rest(e);
		else
			think(e);
	}
	printf("philo[%d] is dead\n", e->nb); // mettre write, printf pas viable //
	return (NULL);
}

static void		init_threads_mutex(pthread_t *philo, t_env *e)
{
	int i;

	i = 0;
	count = -1;
	while (i < 7)
	{
		pthread_mutex_init(&g_pain[i], NULL);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		e[i].life = MAX_LIFE;
		e[i].is_eat = false;
		e[i].is_rest = false;
		e[i].is_think = false;
		pthread_create(&philo[i], NULL, mrPhilo, &e[i]);
		i++;
	}
}

int				main(void)
{
	pthread_t			philo[7];
	t_env				e[7];
	
	pthread_mutex_init(&g_lock, NULL);
	init_threads_mutex(philo, e);
	show_info(e);
	//if key == exit
	del_ressources(g_pain, philo);
	pthread_mutex_destroy(&g_lock);
	return (0);
}
