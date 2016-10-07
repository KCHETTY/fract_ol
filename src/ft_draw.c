/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:53:23 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 08:39:37 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw(t_global *g)
{
	g->mlx.x = 0;
	g->mlx.y = 0;
	if (ft_strcmp("A", g->fract.str) == 0)
		mandelbrot(g);
	else if (ft_strcmp("B", g->fract.str) == 0)
		julia(g);
	else if (ft_strcmp("C", g->fract.str) == 0)
		burning_ship(g);
}
