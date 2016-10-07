/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 07:19:32 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 07:54:47 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	new_image(t_global *g)
{
	mlx_destroy_image (g->mlx.mlx, g->mlx.img);
    g->mlx.img = mlx_new_image(g->mlx.mlx, WIN_W, WIN_H);
	g->mlx.data = mlx_get_data_addr(g->mlx.img, &g->mlx.bpp, &g->mlx.size_line,
			&g->mlx.endian);
	draw(g);
	mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, g->mlx.img, 0, 0);
}
