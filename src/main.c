/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:06:11 by kchetty           #+#    #+#             */
/*   Updated: 2016/09/28 13:54:25 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	calculations(t_glob *g)
{
	double y = 0;
	double x = 0;
	int	r; 
	int green; 
	int	b;
	r = 0;
	g = 0;
	b = 0;
	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
	  double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
	  //int color; //the RGB color value for the pixel
	  int maxIterations = 128; //after how much iterations the function should stop

	    //draw the fractal
	x = 0;
	y = 0;
	printf("TESTL\n");
	while(y < WIN_H)
	{
		while (x < WIN_W)
		{
			printf("Tesy\n");
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			g->brot.cReal = 1.5 * (x - WIN_W/ 2) / (0.5 * zoom * WIN_W) + moveX;
			printf("jfshs f\n");
			g->brot.cImaginary = (y - WIN_H / 2) / (0.5 * zoom * WIN_H) + moveY;
			printf("NEW");
			g->brot.newReal = g->brot.newImaginary = g->brot.oldReal = g->brot.oldImaginary = 0; //these should start at 0,0
	     	 //i will represent the number of iterations
	      	int i;
		  	i = 0;
	      	//start the iteration process
			printf("FRSE");
			while (i < maxIterations)
	      	{
	        	//remember value of previous iteration
	        	g->brot.oldReal = g->brot.newReal;
	        	g->brot.oldImaginary = g->brot.newImaginary;
	        	//the actual iteration, the real and imaginary part are calculated
	        	g->brot.newReal = g->brot.oldReal * g->brot.oldReal - 
					g->brot.oldImaginary * g->brot.oldImaginary + g->brot.cReal;
	        	g->brot.newImaginary = 2 * g->brot.oldReal * 
					g->brot.oldImaginary + g->brot.cImaginary;
			   	//if the point is outside the circle with radius 2: stop
	        	if((g->brot.newReal * g->brot.newReal + g->brot.newImaginary * 
							g->brot.newImaginary) > 4)
				break;
				i++;
	  		}
			printf("test\n");
	      //use color model conversion to get rainbow palette, make brightness black if maxIterations      //draw the pixel
		  	r = i % 256;
		    green = i % 256;
			b = i % 256;
			g->mlx.data[((int)x + (int)y * WIN_W) * 4 + 2] = (unsigned char)r;
			g->mlx.data[((int)x + (int)y * WIN_W) * 4 + 1] = (unsigned char)green;
			g->mlx.data[((int)x + (int)y * WIN_W) * 4] = (unsigned char)b;	   
		  	x++;
	    }
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_glob	g;

	if (argc == 2)
	{
		printf("%s", argv[0]);
		g.mlx.mlx = mlx_init();
		g.mlx.win = mlx_new_window(g.mlx.mlx, WIN_W, WIN_H, "Fract_ol");
		g.mlx.img = mlx_new_image(g.mlx.mlx, WIN_W, WIN_H);
		g.mlx.data = mlx_get_data_addr(g.mlx.img, &g.mlx.bpp, &g.mlx.size_line
				, &g.mlx.endian);
		calculations(&g);
		mlx_put_image_to_window(g.mlx.mlx, g.mlx.win, g.mlx.img, 0, 0);
		mlx_loop(g.mlx.mlx);


	}
	else
		ft_putstr("CHODE!!");
	return (0);
}
