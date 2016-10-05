/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:22:14 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/05 07:49:45 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	get_colour(t_global *g, int i)
{
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line) + 1] = i % 255;
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line)] = i % 225;
		g->mlx.data[((int)g->mlx.x * 4) +
			((int)g->mlx.y * g->mlx.size_line) + 2] = i % 155;
}
