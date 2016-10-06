/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 08:10:02 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/06 07:55:06 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int       expose(t_global *g)
{
	if (g->mlx.win && g->mlx.img)
	{
		ft_putstr("Creating Image");
		mlx_clear_window(0, g->mlx.win);
		mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, g->mlx.img, 0, 0);
	}
	return (0);
}

void	init(t_global *g)
{	
	g->mlx.mlx = mlx_init();
	g->mlx.win = mlx_new_window(g->mlx.mlx, WIN_W, WIN_H, "Fract_ol");
	g->mlx.img = mlx_new_image(g->mlx.mlx, WIN_W, WIN_H);
	g->mlx.data = mlx_get_data_addr(g->mlx.img, &g->mlx.bpp, &g->mlx.size_line,
			&g->mlx.endian);
	g->fract.zoom = ZOOM;
	g->fract.c_real = -0.7;
	g->fract.c_im = -0.27015;
	g->fract.new_real = 0;
	g->fract.new_im = 0;
	g->fract.old_real = 0;
	g->fract.old_im = 0;
	g->mlx.x = 0;
	g->fract.move_y = 0;
	g->fract.move_x = 0;
	g->mlx.y = 0;
	g->mlx.maxiterations = 500;
}

int		main(int argc, char **argv)
{
	t_global	g;

	g.fract.str = argv[1];
	if (argc == 2)
	{
		init(&g);
		//mlx_expose_hook(g.mlx.mlx, &expose, &g);
		mlx_hook(g.mlx.win, 2, (1L << 0), &key_press, &g);
		mlx_hook(g.mlx.win, 3, (1L << 1), &key_release, NULL);
		mlx_hook(g.mlx.win, 17, 0L, &quitwin, &g.mlx);
		mlx_mouse_hook(g.mlx.win, &mouse_hook, &g);
		mlx_loop(g.mlx.mlx);
	}
	else
		printf("CHODE!!");
	return (0);
}
