/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 08:48:48 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/30 08:57:32 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		quitwin(void)
{
	exit(0);
}

int		key_press(int keycode, t_global *g)
{
	if (keycode == KB_ESC)
		exit(0);
	if (keycode == KB_SPACE)
	{
		g->mlx.img = mlx_new_image(g->mlx.mlx, WIN_W, WIN_H);
		g->mlx.data = mlx_get_data_addr(g->mlx.img, &g->mlx.bpp, &g->mlx.size_line,
				&g->mlx.endian);
		if (ft_strcmp("Mandelbrot", g->fract.str) == 0)
			Mandelbrot(g);
		else if (ft_strcmp("Julia", g->fract.str) == 0)
			Julia(g);
		else if (ft_strcmp("Test", g->fract.str) == 0)
			printf("Error\n");

		mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, g->mlx.img, 0, 0);
	}
	return (0);
}

int		key_release(int keycode)
{
	if (keycode == KB_LEFT)
		printf("Hey\n");
	/*if (keycode == KB_RIGHT)
	  g->p.right = 0;
	  if (keycode == KB_UP)
	  g->p.up = 0;
	  if (keycode == KB_DOWN)
	  g->p.down = 0;*/
	return (0);
}
