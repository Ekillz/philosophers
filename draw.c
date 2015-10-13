/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 12:38:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/13 18:27:05 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		choose_color(int *color, t_env *e)
{
	if (e->is_eat)
		*color = 0xff0000;
	else if (e->is_rest)
		*color = 0x00ff00;
	else
		*color = 0x000080;
}

static void		draw_circle(t_graph *t, int radius, int originx, int originy)
{
	int y;
	int x;

	y = -radius;
	x = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				mlx_put_pixel_to_img(t, originx + (x * 2),
						originy + (y * 2), t->color);
			x++;
		}
		y++;
	}
}

static void		show_state_info(t_graph *t)
{
	int i;

	i = 0;
	t->color = 0xff0000;
	draw_circle(t, 20, 50, 50);
	t->color = 0x00ff00;
	draw_circle(t, 20, 150, 50);
	t->color = 0x000080;
	draw_circle(t, 20, 250, 50);
	expose_hook(t);
	show_header_info(t);
}

static void		draw_philos(t_graph *t)
{
	int i;
	int coef;
	int x;
	int y;

	i = 0;
	coef = 1;
	while (i < 7)
	{
		x = HEIGHT / 2 + cos(coef) * 200;
		y = HEIGHT / 2 - sin(coef) * 200;
		t->e[i].x = x;
		t->e[i].y = y;
		choose_color(&t->color, &t->e[i]);
		draw_circle(t, 20, x, y);
		coef += 61;
		i++;
	}
}

void			draw_scene(t_graph *t)
{
	t->color = 0xff0000;
	draw_circle(t, 100, HEIGHT / 2, HEIGHT / 2);
	draw_philos(t);
	expose_hook(t);
	show_state_info(t);
}
