/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 12:44:39 by emammadz          #+#    #+#             */
/*   Updated: 2015/10/13 15:51:19 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	declare_and_check_mlx_error(t_graph *e)
{
	if (!(e->mlx = mlx_init()))
	{
		write(2, "mlx init error\n", 15);
		exit(0);
	}
	else if (!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Philosophers")))
	{
		write(2, "mlx win error\n", 14);
		exit(0);
	}
}

void	declarations_mlx(t_graph *e)
{
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->size_line, &e->endian);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 1L << 0, &key_press_hook, e);
}

void	mlx_put_pixel_to_img(t_graph *e, int x, int y, int color)
{
	ft_memcpy(&e->img[(x * 4) + (y * e->size_line)], &color, (sizeof(size_t)));
}

int		expose_hook(t_graph *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		key_press_hook(int keycode, t_graph *e)
{
	(void)e;
	if (keycode == 53)
		exit(0);
	else if (keycode == 15)
	{
		del_ressources();
		exit(0);
	}
	return (0);
}
