/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:22:12 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/13 17:22:51 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

pthread_mutex_t		g_lock;
pthread_mutex_t		g_pain[7];
pthread_t			g_philo[7];

void			del_ressources(void)
{
	int i;

	i = 0;
	while (i < 7)
	{
		pthread_mutex_destroy(&g_pain[i]);
		i++;
	}
}

static int		eat(t_env *e)
{
	int nb;
	int t0;
	int t1;

	t0 = -1;
	t1 = -1;
	nb = e->nb - 1;
	e->nb == 0 ? (nb = 6) : 0;
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

static void		*mrphilo(void *arg)
{
	t_env			*e;
	static int		count = -1;

	e = (t_env *)arg;
	pthread_mutex_trylock(&g_lock);
	count++;
	e->nb = count;
	pthread_mutex_unlock(&g_lock);
	while (e->life > 0)
	{
		if (eat(e))
			rest(&e->is_rest);
		else if (!think(e, g_pain))
			rest(&e->is_rest);
	}
	return (NULL);
}

static void		init_threads_mutex(pthread_t *philo, t_env *e, t_graph *t)
{
	int i;

	i = 0;
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
		pthread_create(&philo[i], NULL, mrphilo, &e[i]);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		pthread_detach(philo[i]);
		i++;
	}
	t->e = e;
}

int				main(void)
{
	t_env				*e;
	t_graph				t;

	e = malloc(sizeof(t_env) * 7);
	t.time = time(0);
	t.dead = -1;
	pthread_mutex_init(&g_lock, NULL);
	init_threads_mutex(g_philo, e, &t);
	declare_and_check_mlx_error(&t);
	declarations_mlx(&t);
	mlx_loop_hook(t.mlx, func_test, &t);
	mlx_loop(t.mlx);
	pthread_mutex_destroy(&g_lock);
	return (0);
}
