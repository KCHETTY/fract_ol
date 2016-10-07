/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:09:09 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 09:08:25 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		quitwin(void)
{
	exit(0);
}

int		key_press(int keycode, t_global *g)
{
	if (keycode == KB_ESC)
		exit(0);
	if (keycode == KB_RIGHT)
		g->fract.move_x -= 0.2 / ZOOM;
	if (keycode == KB_LEFT)
		g->fract.move_x += 0.2 / ZOOM;
	if (keycode == KB_DOWN)
		g->fract.move_y -= 0.2 / ZOOM;
	if (keycode == KB_UP)
		g->fract.move_y += 0.2 / ZOOM;
	if (keycode == KB_R)
	{
		g->fract.move_x = 0;
		g->fract.move_y = 0;
		g->fract.zoom = ZOOM;
	}
	if (keycode == KB_L)
		g->fract.lock_state = !g->fract.lock_state;
	new_image(g);
	return (0);
}

int		key_release(int keycode)
{
	if (keycode == KB_LEFT)
		ft_putstr("LEFT\n");
	if (keycode == KB_RIGHT)
		ft_putstr("RIGHT\n");
	if (keycode == KB_UP)
		ft_putstr("UP\n");
	if (keycode == KB_DOWN)
		ft_putstr("DOWN\n");
	return (0);
}
