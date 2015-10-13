/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 13:16:08 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/13 17:22:52 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include "mlx/mlx.h"

# define SECOND			1000000
# define MAX_LIFE		15
# define EAT_T			1
# define REST_T			1
# define THINK_T		1
# define TIMEOUT		30

# define HEIGHT			1000
# define WIDTH			1000

typedef struct			s_env
{
	int					x;
	int					y;
	int					nb;
	int					life;
	bool				is_eat;
	bool				is_rest;
	bool				is_think;
}						t_env;

typedef struct			s_graph
{
	void				*mlx;
	void				*img_ptr;
	void				*win;
	char				*img;
	int					bpp;
	int					size_line;
	int					endian;
	int					time;
	int					color;
	int					dead;
	t_env				*e;
}						t_graph;

void					show_info(t_env *e);
void					del_ressources(void);
int						think(t_env *e, pthread_mutex_t *g_pain);
void					rest(bool *rest);
void					life_steal(t_env *e, int *dead);
void					show_philo(t_graph *t, t_env *e);
void					draw_scene(t_graph *t);
int						func_test(t_graph *param);

void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					ft_freetab(char **tab);
void					ft_bzero(void *s, size_t n);
char					*ft_itoa(int n);

void					declarations_mlx(t_graph *e);
void					declare_and_check_mlx_error(t_graph *e);
void					mlx_put_pixel_to_img(t_graph *e,
		int x, int y, int color);
int						expose_hook(t_graph *e);
int						key_press_hook(int keycode, t_graph *e);
void					show_header_info(t_graph *t);
#endif
