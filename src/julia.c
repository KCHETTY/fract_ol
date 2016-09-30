/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 08:41:13 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/30 08:54:47 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	Julia(t_global *g)
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
			g->fract.new_real = 1.5 * (g->mlx.x - WIN_W / 2) / (0.5 *
					ZOOM * WIN_W) + movex;
			g->fract.new_im = (g->mlx.y - WIN_H / 2) / (0.5 *
					ZOOM * WIN_H) + movey;
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
