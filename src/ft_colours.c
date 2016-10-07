/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:22:14 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 13:35:10 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	mod_colour(int keycode, t_global *g)
{
	if (keycode == KB_INC)
	{
		g->mlx.red += 1;
		g->mlx.green += 1;
		g->mlx.blue += 1;
	}
	else if (keycode == KB_DEC)
	{
		g->mlx.red -= 1;
		g->mlx.green -= 1;
		g->mlx.blue -= 1;
	}
}

void	get_colour(t_global *g, int i)
{
	if (g->mlx.invert == 0)
	{
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line) + 1] = i % 233 * g->mlx.green;
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line)] = i % 256 * g->mlx.blue;
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line) + 2] = i % 123 * g->mlx.red;
	}
	else if (g->mlx.invert == 1)
	{
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line) + 1] =
			(unsigned char)(sin(0.013 * i + g->mlx.green) * 230 + 25);
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line) + 2] =
			(unsigned char)(sin(0.016 * i + g->mlx.red) * 230 + 25);
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line)] =
			(unsigned char)(sin(0.01 * i + g->mlx.blue) * 230 + 25);
	}
}

void	get_colour2(t_global *g)
{
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line) + 1] = 57;
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line)] = 98;
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line) + 2] = 45;
}
