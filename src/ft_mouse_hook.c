/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:10:01 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/05 08:17:41 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int mouse_move, int x, int y, t_global *g)
{
	double relx;
	double rely;
	
	mlx_destroy_image (g->mlx.mlx, g->mlx.img);
	g->mlx.img = mlx_new_image(g->mlx.mlx, WIN_W, WIN_H);
	g->mlx.data = mlx_get_data_addr(g->mlx.img, &g->mlx.bpp, &g->mlx.size_line,
			&g->mlx.endian);

	printf("%d\n %d and %d\n", mouse_move, x, y);
	
	relx = x - (WIN_W / 2);
	rely = y - (WIN_H / 2);
	
	printf("%f and %f\n", relx, rely);
	//re_init(g);

	if (mouse_move == SCROLL_UP)
	{
		g->fract.zoom *= 0.2;
		g->fract.move_x += 0.2 * (relx / (WIN_W * g->fract.zoom));
		g->fract.move_x += 0.2 * (relx / (WIN_W * g->fract.zoom));
	}
	if (mouse_move == SCROLL_DOWN)
	{
		g->fract.zoom /= 0.2;
		g->fract.move_x -= (relx / (WIN_W * g->fract.zoom));
		g->fract.move_y -= (rely / (WIN_H * g->fract.zoom));
	}

	draw(g);

	mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, g->mlx.img, 0, 0);
	return (0);
}
