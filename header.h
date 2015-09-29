/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:16:08 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/29 16:53:01 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# define SECOND 1000000
# define MAX_LIFE 15
typedef struct	s_env
{
	int					nb;
	int					life;
	bool				is_eat;
	bool				is_think;
	bool				is_chill;
	pthread_mutex_t		pain[7];
}				t_env;

void					main_loop(t_env *e);
#endif
