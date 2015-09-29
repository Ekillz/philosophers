/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:22:12 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/29 13:43:26 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

pthread_mutex_t g_lock;

void	*baguette(void *arg)
{
	(void)arg;
	return (NULL);
}

void	*mrPhilo(void *arg)
{
	(void)arg;
	return (NULL);
}

void	init_threads(pthread_t *philo, pthread_t *pain, t_env *e)
{
	int i;

	i = 0;
	while (i < 7)
	{
		e[i].life = MAX_LIFE;
		e[i].is_eat = false;
		e[i].is_think = false;
		e[i].is_chill = false;
		pthread_create(&philo[i], NULL, mrPhilo, &e[i]);
		pthread_create(&pain[i], NULL, baguette, "pain");
		i++;
	}
}

int		main(void)
{
	pthread_t	philo[7];
	pthread_t	pain[7];
	t_env		e[7];

	init_threads(philo, pain, e);
	printf("life = %d\n", e[0].life);
	//pthread_mutex_lock(&g_lock);
	//pthread_mutex_unlock(&g_lock);
	//pthread_mutex_init(&g_lock, NULL);
	//pthread_mutex_destroy(&g_lock);
	return (0);
}
