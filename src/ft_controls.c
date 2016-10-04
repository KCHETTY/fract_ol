/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:09:09 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/04 08:21:55 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		quitwin(void)
{
	exit(0);
}

int		key_press(int keycode, t_global *g)
{
	g->mlx.img = mlx_new_image(g->mlx.mlx, WIN_W, WIN_H);
	g->mlx.data = mlx_get_data_addr(g->mlx.img, &g->mlx.bpp, &g->mlx.size_line,
			&g->mlx.endian);

	init(g);

	if (keycode == KB_ESC)
		exit(0);
	if (keycode == KB_LEFT)
		g->fract.move_x = -0.4 / ZOOM;
	if (keycode == KB_RIGHT)
		g->fract.move_x = 0.4 / ZOOM;
	if (keycode == KB_UP)
		g->fract.move_y = 0.4 / ZOOM;
	if (keycode == KB_DOWN)
		g->fract.move_y = -0.4 / ZOOM;

	if (ft_strcmp("Mandelbrot", g->fract.str) == 0)
		Mandelbrot(g);
	else if (ft_strcmp("Julia", g->fract.str) == 0)
		Julia(g);
	else if (ft_strcmp("Test", g->fract.str) == 0)
		printf("Error\n");
	mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, g->mlx.img, 0, 0);

	return (0);
}

int		key_release(int keycode)
{

	if (keycode == KB_LEFT)
		printf("LEFT\n");
	if (keycode == KB_RIGHT)
		printf("RIGHT\n");
	if (keycode == KB_UP)
		printf("UP\n");
	if (keycode == KB_DOWN)
		printf("DOWN\n");

	return (0);
}
