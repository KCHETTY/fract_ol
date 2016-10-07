/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:09:30 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 08:38:14 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		julia_iterations(t_global *g)
{
	int i;

	i = 0;
	while (i < g->mlx.maxiterations)
	{
		g->fract.old_real = g->fract.new_real;
		g->fract.old_im = g->fract.new_im;
		g->fract.new_real = g->fract.old_real * g->fract.old_real -
			g->fract.old_im * g->fract.old_im + g->fract.c_real;
		g->fract.new_im = 2 * g->fract.old_real * g->fract.old_im +
			g->fract.c_im;
		if (sqrt(g->fract.new_real * g->fract.new_real + g->fract.new_im *
					g->fract.new_im) > 4)
		{
			get_colour(g, i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	julia(t_global *g)
{
	while (g->mlx.y < WIN_H)
	{
		g->mlx.x = 0;
		while (g->mlx.x < WIN_W)
		{
			g->fract.new_real = 1.5 * (g->mlx.x - WIN_W / 2) / (0.5 *
					g->fract.zoom * WIN_W) + g->fract.move_x;
			g->fract.new_im = (g->mlx.y - WIN_H / 2) / (0.5 *
					g->fract.zoom * WIN_H) + g->fract.move_y;
			if (!julia_iterations(g))
				get_colour2(g);
			g->mlx.x++;
		}
		g->mlx.y++;
	}
}
