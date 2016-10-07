/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:10:01 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 07:57:25 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int mouse_move, int x, int y, t_global *g)
{
	double relx;
	double rely;

	printf("%d\n %d and %d\n", mouse_move, x, y);

	relx = x - (WIN_W / 2);
	rely = y - (WIN_H / 2);

	printf("%f and %f\n", relx, rely);
	if (g->fract.zoom == 0)
		g->fract.zoom = 0.1;

	if (mouse_move == SCROLL_UP)
	{
		printf("HI\n");
		g->fract.zoom *= 1.2;
		g->fract.move_x += 0.625 * (relx / (WIN_W * g->fract.zoom));
		g->fract.move_y += 0.625 * (relx / (WIN_W * g->fract.zoom));
	}
	else if (mouse_move == SCROLL_DOWN)
	{
		g->fract.zoom /= 1.2;
		g->fract.move_x -= (relx / (WIN_W * g->fract.zoom));
		g->fract.move_y -= (rely / (WIN_H * g->fract.zoom));
	}

	printf("%s\n", g->fract.str);
	new_image(g);

	return (0);
}

void	map_mouse(t_global *g, double range_min, double range_max)
{
	double range;

	range = range_max - range_min;
	if (range < 0)
		range = 1.0F;
	g->fract.c_real = range_min + ((double)g->fract.point_x
			/ (double)WIN_W) * range;
	g->fract.c_im = range_min + ((double)g->fract.point_y
			/ (double)WIN_H) * range;
}

int		mouse_move(int x, int y, t_global *g)
{
	if ((x <= WIN_W && x >= 0) && (y <= WIN_H && y >= 0 ) && (!g->fract.lock_state))
	{
		if (g->fract.zoom == 1)
		{
			g->fract.point_x = x;
			g->fract.point_y = y;
		}
		else
		{
			if ((float)abs(g->fract.oldx - x) >= g->fract.zoom * 2.0)
			{
				g->fract.win_w = (g->fract.oldx - x > 0) ? g->fract.win_w - 1 : g->fract.win_w + 1;
				g->fract.oldx = x;
			}
			if ((float)abs(g->fract.oldy - y) >= g->fract.zoom * 2.0)
			{
				g->fract.win_h = (g->fract.oldy - y > 0) ? g->fract.win_h - 1 : g->fract.win_h + 1;
				g->fract.oldy = y;
			}
		}
		map_mouse(g, -1.0F, 1.0F);

		new_image(g);
	}
	return (0);
}
