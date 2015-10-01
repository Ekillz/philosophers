/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:16:08 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/01 13:22:15 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# define SECOND		1000000
# define MAX_LIFE	7
# define EAT_T		1
# define REST_T		1
# define THINK_T	1
# define TIMEOUT	60

typedef struct	s_env
{
	int					nb;
	int					life;
	bool				is_eat;
	bool				is_rest;
	bool				is_think;
}				t_env;

void					show_info(t_env *e);
void					del_ressources(pthread_mutex_t *g_pain, pthread_t *philo);
void					think(t_env *e);
void					life_steal(t_env *e);
#endif
