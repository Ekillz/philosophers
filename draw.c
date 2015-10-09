/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 12:38:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/09 17:15:06 by emammadz         ###   ########.fr       */
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

static void		draw_circle(t_graph *t, int radius, int originX, int originY)
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
				mlx_put_pixel_to_img(t, originX + x + x , originY + y + y, t->color);
			x++;
		}
		y++;
	}
}

static void     show_state_info(t_graph *t)
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

	mlx_string_put(t->mlx, t->win, 40, 50, 0xffff00, "EAT");
	mlx_string_put(t->mlx, t->win, 140, 50, 0xffff00, "REST");
	mlx_string_put(t->mlx, t->win, 240, 50, 0xffff00, "THINK");
	mlx_string_put(t->mlx, t->win, 500, 200, 0xffff00, ft_itoa(time(0) - t->time));
	mlx_string_put(t->mlx, t->win, 400, 20, 0xffff00, "MAX_LIFE: ");
	mlx_string_put(t->mlx, t->win, 500, 20, 0xffff00, ft_itoa(MAX_LIFE));
	mlx_string_put(t->mlx, t->win, 400, 40, 0xffff00, "EAT: ");
	mlx_string_put(t->mlx, t->win, 500, 40, 0xffff00, ft_itoa(EAT_T));
	mlx_string_put(t->mlx, t->win, 400, 60, 0xffff00, "REST: ");
	mlx_string_put(t->mlx, t->win, 500, 60, 0xffff00, ft_itoa(REST_T));
	mlx_string_put(t->mlx, t->win, 400, 80, 0xffff00, "THINK: ");
	mlx_string_put(t->mlx, t->win, 500, 80, 0xffff00, ft_itoa(THINK_T));
	mlx_string_put(t->mlx, t->win, 400, 100, 0xffff00, "TIMEOUT: ");
	mlx_string_put(t->mlx, t->win, 500, 100, 0xffff00, ft_itoa(TIMEOUT));
	while (i < 7)
	{
		mlx_string_put(t->mlx, t->win, t->e[i].x, t->e[i].y, 0xffff00, ft_itoa(t->e[i].life));
		i++;
	}
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
	ft_bzero(t->img, t->bpp * HEIGHT + WIDTH * t->size_line);
}
