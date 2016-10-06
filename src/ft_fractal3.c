
#include "fract_ol.h"

int		b_ship_iterations(t_global *g)
{
	int	i;

	i = 0;
	while (i < g->mlx.maxiterations)
	{
		g->fract.old_real = fabs(g->fract.new_real);
		g->fract.old_im = fabs(g->fract.new_im);
		g->fract.new_real = g->fract.old_real * g->fract.old_real - g->fract.old_im * g->fract.old_im + g->fract.c_real;
		g->fract.new_im = 2 * g->fract.old_real * g->fract.old_im + g->fract.c_im;
		if (sqrt(g->fract.new_real * g->fract.new_real + g->fract.new_im * g->fract.new_im) > 3)
		{
			get_colour(g, i);
			return (1);	
		}
		i++;
	}
	return (0);
}

void	burning_ship(t_global *g)
{

	while (g->mlx.y < WIN_H)
	{
		g->mlx.x = 0;
		while (g->mlx.x < WIN_W)
		{
			g->fract.c_real = 1.5 * (g->mlx.x - WIN_W / 2) / (0.5 * g->fract.zoom * WIN_W) + g->fract.move_x;
			g->fract.c_im = (g->mlx.y - WIN_H / 2) / (0.5 * g->fract.zoom * WIN_H) + g->fract.move_y;
			g->fract.new_real = 0;
			g->fract.new_im = 0;
			g->fract.old_real = 0;
			g->fract.old_im = 0;

			if (!b_ship_iterations(g))
				get_colour2(g);
			
			g->mlx.x++;
		}
		g->mlx.y++;
	}
}


int		expose(t_env *env)
{
	if (env->win && env->img.img)
	{
		ft_printf("exposing");
		mlx_clear_window(0, env->win);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	}
	return (0);
}
