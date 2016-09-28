/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:00:45 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/28 13:54:22 by kchetty          ###   ########.fr       */
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

# define WIN_H 320
# define WIN_W 320

typedef struct	s_manbrot
{
	double		cReal;
	double		cImaginary;
	double		newReal;
	double		newImaginary;
	double		oldReal;
	double		oldImaginary;
	int			size_line;

}				t_manbrot;

typedef	struct	s_mlx
{
	void			*mlx;
	void			*win;
	int				p_x;
	int				p_y;
	void			*img;
	int				**map;
	char			*data;							
	int				fd;
	int				bpp;
	unsigned int	color;
	int				size_line;
	int				endian;

}				t_mlx;

typedef	struct	s_glob
{
	t_mlx		mlx;
	t_manbrot	brot;

}				t_glob;

#endif
