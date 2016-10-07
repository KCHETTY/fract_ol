/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:22:14 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 08:46:19 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	get_colour(t_global *g, int i)
{
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line) + 1] = i % 1;
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line)] = i % 256;
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line) + 2] = i % 1;
}

void	get_colour2(t_global *g)
{
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line) + 1] = 1;
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line)] = 1;
	g->mlx.data[((int)g->mlx.x * 4) +
		((int)g->mlx.y * g->mlx.size_line) + 2] = 1;
}
