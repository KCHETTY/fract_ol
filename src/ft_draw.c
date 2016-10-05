/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:53:23 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/05 07:49:14 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw(t_global *g)
{
	if (ft_strcmp("Mandelbrot", g->fract.str) == 0)
		Mandelbrot(g);
	else if (ft_strcmp("Julia", g->fract.str) == 0)
		Julia(g);
	else if (ft_strcmp("Test", g->fract.str) == 0)
		printf("Error\n");
	else
		printf("Error\n");
}
