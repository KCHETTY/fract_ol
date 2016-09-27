/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antricht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 11:32:06 by antricht          #+#    #+#             */
/*   Updated: 2016/09/27 11:45:59 by antricht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <string.h>

static int		key_event(int keycode, void **a)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx, win);
		return(0);
	}
	return (0);
}

int		main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1000, 1000, "Fractol");
	mlx_key_hook(win, &key_event, NULL);
	mlx_loop(mlx);
}
