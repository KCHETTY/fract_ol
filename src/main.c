/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 08:10:02 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 09:01:16 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		expose(t_global *g)
{
	if (g->mlx.win && g->mlx.img)
	{
		ft_putstr("Creating Image");
		mlx_clear_window(g->mlx.mlx, g->mlx.win);
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
	g->fract.win_h = WIN_H;
	g->fract.win_w = WIN_W;
	g->fract.old_im = 0;
	g->mlx.x = 0;
	g->fract.lock_state = 1;
	g->fract.move_y = 0;
	g->fract.move_x = 0;
	g->mlx.y = 0;
	g->mlx.maxiterations = MAX_ITER;
}

int		main(int argc, char **argv)
{
	t_global	g;

	if (argc == 2 && (ft_strcmp(argv[1], "A") == 0 ||
				ft_strcmp(argv[1], "B") == 0 || ft_strcmp(argv[1], "C") == 0))
	{
		g.fract.str = argv[1];
		init(&g);
		mlx_expose_hook(g.mlx.win, &expose, &g);
		mlx_hook(g.mlx.win, 2, (1L << 0), &key_press, &g);
		mlx_hook(g.mlx.win, 3, (1L << 1), &key_release, NULL);
		mlx_hook(g.mlx.win, 17, 0L, &quitwin, &g.mlx);
		mlx_hook(g.mlx.win, 6, 1L << 6, &mouse_move, &g);
		mlx_mouse_hook(g.mlx.win, &mouse_hook, &g);
		mlx_loop(g.mlx.mlx);
	}
	else
	{
		ft_putstr("Incorrect input!..\n");
		ft_putstr("Use: ./fractol A or B or C\n");
		ft_putstr("A: Mandelbrot set\n");
		ft_putstr("B: Julia set\n");
		ft_putstr("C: Burning Ship\n");
	}
	return (0);
}
