/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:00:45 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/07 07:35:50 by kchetty          ###   ########.fr       */
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
# include <math.h>

# define KB_ESC 53
# define KB_SPACE 49
# define KB_UP 126
# define KB_DOWN 125
# define KB_LEFT 124
# define KB_RIGHT 123
# define KB_R 15
# define KB_L 37

# define L_KB_ESC 65307
# define L_KB_SPACE 32
# define L_KB_UP 65362
# define L_KB_DOWN 65364
# define L_KB_RIGHT 65361
# define L_KB_LEFT 65363
# define L_SCROLL_UP 4
# define L_SCROLL_DOWN 5
 
# define ZOOM 1

# define SCROLL_UP 5
# define SCROLL_DOWN 4

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
	double		zoom;
	double		win_w;
	double		win_h;
	double		point_x;
	double		point_y;
	int			lock_state;
	double		mapped_point_x;
	double		mapped_point_y;
	int			oldx;
	int			oldy;

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
int     mouse_move(int x, int y, t_global *g);

//colours.c
void	get_colour(t_global *g, int i);
void	get_colour2(t_global *g);

//draw.c
void	draw(t_global *g);

//fractal3.c
void	burning_ship(t_global *g);

//redraw.c
void	new_image(t_global *g);

#endif
