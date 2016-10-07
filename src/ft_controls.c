/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 08:09:09 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 07:53:17 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		quitwin(void)
{
	exit(0);
}

void	re_init(t_global *g)
{
	//g->fract.c_real = -0.7;
	//g->fract.c_im = -0.27015;
	//g->fract.new_real = 0;
	//g->fract.new_im = 0;
	//g->fract.old_real = 0;
	//g->fract.old_im = 0;
	g->mlx.x = 0;
	g->mlx.y = 0;	
}

int		key_press(int keycode, t_global *g)
{
	
	re_init(g);

	printf("%d\n", keycode);

	if (keycode == KB_ESC)
		exit(0);
	if (keycode == KB_LEFT)
		g->fract.move_x -= 0.2 / ZOOM;
	if (keycode == KB_RIGHT)
		g->fract.move_x += 0.2 / ZOOM;
	if (keycode == KB_UP)
		g->fract.move_y += 0.2 / ZOOM;
	if (keycode == KB_DOWN)
		g->fract.move_y -= 0.2 / ZOOM;
	if (keycode == KB_R)
	{
		g->fract.move_x = 0;
		g->fract.move_y = 0;
		g->fract.zoom = ZOOM;
	}
	if (keycode == KB_L)
		g->fract.lock_state = !g->fract.lock_state;
	//if (keycode == )
	//if (keycode == )	
		

	new_image(g);
	return (0);
}

int		key_release(int keycode)
{

	if (keycode == KB_LEFT)
		printf("LEFT\n");
	if (keycode == KB_RIGHT)
		printf("RIGHT\n");
	if (keycode == KB_UP)
		printf("UP\n");
	if (keycode == KB_DOWN)
		printf("DOWN\n");

	return (0);
}
