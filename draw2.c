/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 15:39:49 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/19 12:28:22 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			get_philo_coord(t_env *e)
{
	e[0].x = 699;
	e[0].y = 491;
	e[1].x = 634;
	e[1].y = 352;
	e[2].x = 439;
	e[2].y = 309;
	e[3].x = 322;
	e[3].y = 408;
	e[4].x = 331;
	e[4].y = 607;
	e[5].x = 456;
	e[5].y = 695;
	e[6].x = 608;
	e[6].y = 668;
}

void			get_pos(t_graph *t)
{
	int i;
	int e;

	e = 0;
	t->posx = malloc(sizeof(int) * 7);
	t->posy = malloc(sizeof(int) * 7);
	while (e < 7)
	{
		i = 0;
		while (i < 7)
		{
			if (t->e[i].nb == e)
			{
				t->posx[e] = t->e[i].x;
				t->posy[e] = t->e[i].y;
				e++;
				break ;
			}
			i++;
		}
	}
	t->posx[e] = 0;
	t->posy[e] = 0;
}

static char		*get_char(int which)
{
	char *new;

	if (which == -1)
		new = ft_itoa(MAX_LIFE);
	else if (which == -2)
		new = ft_itoa(EAT_T);
	else if (which == -3)
		new = ft_itoa(REST_T);
	else if (which == -4)
		new = ft_itoa(THINK_T);
	else if (which == -5)
		new = ft_itoa(TIMEOUT);
	else
		new = ft_itoa(which);
	return (new);
}

static void		show_life(t_graph *t, char **ptr)
{
	int i;

	i = 0;
	while (i < 7)
	{
		write(1, "", 0);
		mlx_string_put(t->mlx, t->win,
				t->posx[i], t->posy[i], 0xffff00,
				ptr[i + 5] = get_char(*(t->lifes[i])));
		mlx_string_put(t->mlx, t->win,
				t->posx[i], t->posy[i] - 35, 0xffff00,
				ptr[i + 12] = get_char(i));
		i++;
	}
	ptr[19] = NULL;
	ft_freetab(ptr);
}

void			show_header_info(t_graph *t)
{
	int		i;
	char	*t_ime;
	char	**ptr;

	t_ime = ft_itoa(time(0) - t->time);
	i = 0;
	ptr = malloc(sizeof(char *) * 20);
	mlx_string_put(t->mlx, t->win, 40, 50, 0xffff00, "EAT");
	mlx_string_put(t->mlx, t->win, 140, 50, 0xffff00, "REST");
	mlx_string_put(t->mlx, t->win, 240, 50, 0xffff00, "THINK");
	mlx_string_put(t->mlx, t->win, 500, 200, 0xffff00, t_ime);
	mlx_string_put(t->mlx, t->win, 400, 20, 0xffff00, "MAX_LIFE: ");
	mlx_string_put(t->mlx, t->win, 500, 20, 0xffff00, ptr[0] = get_char(-1));
	mlx_string_put(t->mlx, t->win, 400, 40, 0xffff00, "EAT: ");
	mlx_string_put(t->mlx, t->win, 500, 40, 0xffff00, ptr[1] = get_char(-2));
	mlx_string_put(t->mlx, t->win, 400, 60, 0xffff00, "REST: ");
	mlx_string_put(t->mlx, t->win, 500, 60, 0xffff00, ptr[2] = get_char(-3));
	mlx_string_put(t->mlx, t->win, 400, 80, 0xffff00, "THINK: ");
	mlx_string_put(t->mlx, t->win, 500, 80, 0xffff00, ptr[3] = get_char(-4));
	mlx_string_put(t->mlx, t->win, 400, 100, 0xffff00, "TIMEOUT: ");
	mlx_string_put(t->mlx, t->win, 500, 100, 0xffff00, ptr[4] = get_char(-5));
	show_life(t, ptr);
	free(t_ime);
}
