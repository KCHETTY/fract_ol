/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:09:09 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/05 08:44:06 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		quitwin(void)
{
	exit(0);
}

void	re_init(t_global *g)
{
	g->fract.c_real = -0.7;
	g->fract.c_im = -0.27015;
	g->fract.new_real = 0;
	g->fract.new_im = 0;
	g->fract.old_real = 0;
	g->fract.old_im = 0;
	g->mlx.x = 0;
	g->mlx.y = 0;	
}

int		key_press(int keycode, t_global *g)
{
	mlx_destroy_image (g->mlx.mlx, g->mlx.img);
	g->mlx.img = mlx_new_image(g->mlx.mlx, WIN_W, WIN_H);
	g->mlx.data = mlx_get_data_addr(g->mlx.img, &g->mlx.bpp, &g->mlx.size_line,
			&g->mlx.endian);
	
	re_init(g);

	if (keycode == KB_ESC)
		exit(0);
	if (keycode == KB_LEFT)
		g->fract.move_x -= 0.4 / ZOOM;
	if (keycode == KB_RIGHT)
		g->fract.move_x += 0.4 / ZOOM;
	if (keycode == KB_UP)
		g->fract.move_y += 0.4 / ZOOM;
	if (keycode == KB_DOWN)
		g->fract.move_y -= 0.4 / ZOOM;
	//if (keycode == )
	//if (keycode == )
	//if (keycode == )	
		
	/*if (ft_strcmp("Mandelbrot", g->fract.str) == 0)
		Mandelbrot(g);
	else if (ft_strcmp("Julia", g->fract.str) == 0)
		Julia(g);
	else if (ft_strcmp("Test", g->fract.str) == 0)
		printf("Error\n");*/

	draw(g);
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
