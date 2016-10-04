/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:10:01 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/04 09:59:55 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int mouse_move, t_global *g)
{
	printf("%d\n", mouse_move);
	re_init(g);

	if (mouse_move == SCROLL_UP)
		g->fract.zoom += 0.2;
	if (mouse_move == SCROLL_DOWN)	
		g->fract.zoom -= 0.2;

	draw(g);

	mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, g->mlx.img, 0, 0);
	return (0);
}
