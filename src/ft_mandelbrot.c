/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:09:46 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/05 10:15:22 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		mandelbrot_colour(t_global *g)
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
		if((g->fract.new_real * g->fract.new_real + g->fract.new_im *
					g->fract.new_im) > 4)
		{
			get_colour(g, i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	Mandelbrot(t_global *g)
{

	//while (1)
	//{
	while (g->mlx.y < WIN_H)
	{
		g->mlx.x = 0;
		while (g->mlx.x < WIN_W)
		{
			g->fract.c_real = 1.5 * (g->mlx.x - (WIN_W / 2)) /
				(0.5 * g->fract.zoom * WIN_W) + g->fract.move_x;
			g->fract.c_im = (g->mlx.y - (WIN_H / 2)) /
				(0.5 * g->fract.zoom * WIN_H) + g->fract.move_y;

			g->fract.new_real = 0;
			g->fract.new_im = 0;
			g->fract.old_real = 0;
			g->fract.old_im = 0;

			/*i = 0;
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
			  {
			  get_colour(g, i);
			  break;
			  }
			  i++;
			  }*/
			if (!mandelbrot_colour(g))
				get_colour2(g);
			g->mlx.x++;
		}
		g->mlx.y++;
	}
	//}
}
