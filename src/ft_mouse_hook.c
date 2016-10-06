/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:10:01 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/06 07:42:30 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int mouse_move, int x, int y, t_global *g)
{
	double relx;
	double rely;
	
	printf("%d\n %d and %d\n", mouse_move, x, y);
	
	relx = x - (WIN_W / 2);
	rely = y - (WIN_H / 2);
	
	printf("%f and %f\n", relx, rely);
	//re_init(g);

	if (mouse_move == SCROLL_UP)
	{
		g->fract.zoom *= 0.2;
		g->fract.move_x += 0.2 * (relx / (WIN_W * g->fract.zoom));
		g->fract.move_x += 0.2 * (relx / (WIN_W * g->fract.zoom));
	}
	else if (mouse_move == SCROLL_DOWN)
	{
		g->fract.zoom /= 0.2;
		g->fract.move_x -= (relx / (WIN_W * g->fract.zoom));
		g->fract.move_y -= (rely / (WIN_H * g->fract.zoom));
	}

	new_image(g);
	return (0);
}
