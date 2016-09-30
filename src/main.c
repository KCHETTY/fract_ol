/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 08:10:02 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/30 08:59:38 by kchetty          ###   ########.fr       */
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
	return (0);
}
