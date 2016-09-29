/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:00:45 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/29 14:34:49 by kchetty          ###   ########.fr       */
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
# define KB_UP 65362
# define KB_DOWN 65364
# define KB_LEFT 65361
# define KB_RIGHT 65363

# define WIN_H 500
# define WIN_W 700

typedef struct	s_manbrot
{
	double		c_real;
	double		c_im;
	double		new_real;
	double		new_im;
	char		*str;
	double		old_real;
	double		old_im;

}				t_manbrot;

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
	t_manbrot	brot;

}				t_global;

#endif
