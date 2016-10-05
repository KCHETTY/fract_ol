/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:00:45 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/05 07:34:29 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACT_OL_H
# define _FRACT_OL_H

# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

# define KB_ESC 53
# define KB_SPACE 49
# define KB_UP 126
# define KB_DOWN 125
# define KB_LEFT 124
# define KB_RIGHT 123

# define ZOOM 1

# define SCROLL_UP 5
# define SCROLL_DOWN 6

# define WIN_H 500
# define WIN_W 700

typedef struct	s_fract
{
	double		c_real;
	double		c_im;
	double		new_real;
	double		new_im;
	char		*str;
	double		old_real;
	double		old_im;
	double		move_x;
	double		move_y;
	int			zoom;

}				t_fract;

typedef	struct	s_mlx
{
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	void			*img;
	int				**map;
	char			*data;							
	int				fd;
	int				bpp;
	unsigned int	color;
	int				size_line;
	int				red;
	int				green;
	int				blue;
	int				endian;
	int				maxiterations;

}				t_mlx;

typedef	struct	s_global
{
	t_mlx		mlx;
	t_fract		fract;

}				t_global;

//julia.c
void	Julia(t_global *g);

//mandelbrot.c
void	Mandelbrot(t_global *g);

//main.c
int		main(int argc, char **argv);
void	init(t_global *g);

//controls.c
void	re_init(t_global *g);
int		key_press(int keycode, t_global *g);
int		key_release(int keycode);
int		quitwin(void);

//mouse_hook.c
int		mouse_hook(int mouse_move, int x, int y, t_global *g);

//colours.c
void	get_colour(t_global *g, int i);

//draw.c
void	draw(t_global *g);

#endif
