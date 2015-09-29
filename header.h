/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:16:08 by emammadz          #+#    #+#             */
/*   Updated: 2015/09/29 13:36:43 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# define MAX_LIFE 15
typedef struct	s_env
{
	int		life;
	bool	is_eat;
	bool	is_think;
	bool	is_chill;
}				t_env;

void		*baguette(void *arg);
void		*mrPhilo(void *arg);
#endif
