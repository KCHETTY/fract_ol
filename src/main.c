/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 08:10:02 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/29 14:43:09 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init(t_global *g)
{
	g->fract.c_real = -0.7;
	g->fract.c_im = 0.27015;
	g->fract.new_real = 0;
	g->fract.new_im = 0;
	g->fract.old_real = 0;
	g->fract.old_im = 0;
	g->mlx.x = 0;
	g->mlx.y = 0;
	g->mlx.maxiterations = 128;
}

int		quitwin(void)
{
	exit(0);
}

void	calc2(t_global *g)
{
	double movex, movey;
	int i;

	movex = 0;
	movey = 0;

	while (g->mlx.y < WIN_H)
	{
		g->mlx.x = 0;
		while (g->mlx.x < WIN_W)
		{
			g->fract.new_real = 1.5 * (g->mlx.x - WIN_W / 2) / (0.5 * 1 * WIN_W) + movex;
			g->fract.new_im = (g->mlx.y - WIN_H / 2) / (0.5 * 1 * WIN_H) + movey;
			i = 0;
			while (i < g->mlx.maxiterations)
			{
				g->fract.old_real = g->fract.new_real;
				g->fract.old_im = g->fract.new_im;
				g->fract.new_real = g->fract.old_real * g->fract.old_real - 
					g->fract.old_im * g->fract.old_im + g->fract.c_real;
				g->fract.new_im = 2 * g->fract.old_real * g->fract.old_im + 
					g->fract.c_im;
				if((g->fract.new_real * g->fract.new_real + g->fract.new_im *
							g->fract.new_im) > 4)
					break;
				i++;
			}
			g->mlx.data[((int)g->mlx.x * 4) +
				((int)g->mlx.y * g->mlx.size_line) + 1] = i % 255;
			g->mlx.data[((int)g->mlx.x * 4) +
				((int)g->mlx.y * g->mlx.size_line)] = i % 225;
			g->mlx.data[((int)g->mlx.x * 4) +
				((int)g->mlx.y * g->mlx.size_line) + 2] = i % 155;
			g->mlx.x++;
		}
		g->mlx.y++;
	}
}

void	calc(t_global *g)
{

	double movex, movey;
	int i;

	movex = -0.5;
	movey = 0;
	//while (1)
	//{
	while (g->mlx.y < WIN_H)
	{
		g->mlx.x = 0;
		while (g->mlx.x < WIN_W)
		{
			g->fract.c_real = 1.5 * (g->mlx.x - (WIN_W / 2)) /
				(0.5 * 1 * WIN_W) + movex;
			g->fract.c_im = (g->mlx.y - (WIN_H / 2)) /
				(0.5 * 1 * WIN_H) + movey;

			g->fract.new_real = 0;
			g->fract.new_im = 0;
			g->fract.old_real = 0;
			g->fract.old_im = 0;

			i = 0;
			while (i < g->mlx.maxiterations)
			{
				g->fract.old_real = g->fract.new_real;
				g->fract.old_im = g->fract.new_im;
				g->fract.new_real = g->fract.old_real * g->fract.old_real -
					g->fract.old_im * g->fract.old_im + g->fract.c_real;
				g->fract.new_im = 2 * g->fract.old_real * g->fract.old_im +
					g->fract.c_im;
				if((g->fract.new_real * g->fract.new_real + g->fract.new_im *
							g->fract.new_im) > 4)
					break;
				i++;
			}
			g->mlx.data[((int)g->mlx.x * 4) +
				((int)g->mlx.y * g->mlx.size_line) + 1] = i % 255;
			g->mlx.data[((int)g->mlx.x * 4) +
				((int)g->mlx.y * g->mlx.size_line)] = i % 225;
			g->mlx.data[((int)g->mlx.x * 4) +
				((int)g->mlx.y * g->mlx.size_line) + 2] = i % 155;
			g->mlx.x++;
		}
		g->mlx.y++;
	}
	//}
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
			calc(g);
		else if (ft_strcmp("Julia", g->fract.str) == 0)
			calc2(g);
		else
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

int		main(int argc, char **argv)
{
	t_global	g;

	g.fract.str = argv[1];
	if (argc == 2)
	{
		printf("%s\n", argv[0]);
		init(&g);
		g.mlx.mlx = mlx_init();
		g.mlx.win = mlx_new_window(g.mlx.mlx, WIN_W, WIN_H, "Fract_ol");
		mlx_hook(g.mlx.win, 2, (1L << 0), &key_press, &g);
		mlx_hook(g.mlx.win, 3, (1L << 1), &key_release, NULL);
		mlx_hook(g.mlx.win, 17, 0L, &quitwin, &g.mlx);
		mlx_loop(g.mlx.mlx);
	}
	else
		printf("CHODE!!");

}
