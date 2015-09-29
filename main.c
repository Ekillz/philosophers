/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:22:12 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/29 17:00:23 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

pthread_mutex_t g_lock; // mettre dans struct //
int				count;

/*static void		*baguette(void *arg)
{
	(void)arg;
	
	return (NULL);
}*/

static void		*mrPhilo(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	pthread_mutex_lock(&g_lock);
	count++;
	e->nb = count;
	pthread_mutex_unlock(&g_lock);
	while (1)
	{
		usleep(SECOND);
		e->life--;
		if (e->life <= 0)
		{
			printf("philo[%d] is dead", e->nb); // mettre write, printf pas viable //
			break;
		}
	}
	return (NULL);
}

static void		init_threads(pthread_t *philo, t_env *e)
{
	int i;

	i = 0;
	count = -1;
	while (i < 7)
	{
		e[i].life = MAX_LIFE;
		e[i].is_eat = false;
		e[i].is_think = false;
		e[i].is_chill = false;
		pthread_mutex_init(&e[i].pain[i], NULL);
		pthread_create(&philo[i], NULL, mrPhilo, &e[i]);
		i++;
	}
}

int				main(void)
{
	pthread_t			philo[7];
	t_env				e[7];

	pthread_mutex_init(&g_lock, NULL);
	init_threads(philo, e);
	main_loop(e);
	//pthread_mutex_destroy(&g_lock);
	return (0);
}
