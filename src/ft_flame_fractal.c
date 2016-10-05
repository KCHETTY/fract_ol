/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flame_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 08:21:43 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/05 08:34:31 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void    flame_fractal(t_global *g)
{
	int i;

	while (g->mlx.y < WIN_H)
	{
		g->mlx.x = 0;
		while (g->mlx.x < WIN_W)
		{
			g->fract.new_real = 1.5 * (g->mlx.x - WIN_W / 2) / (0.5 *
					g->fract.zoom * WIN_W) + g->fract.move_x;
			g->fract.new_im = (g->mlx.y - WIN_H / 2) / (0.5 *
					g->fract.zoom * WIN_H) + g->fract.move_y;
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
			get_colour(g, i);
			g->mlx.x++;
		}
		g->mlx.y++;
	}
}
