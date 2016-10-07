# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 11:55:33 by arnovan-          #+#    #+#              #
#    Updated: 2016/10/07 07:44:14 by kchetty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

CC=clang

CFLAGS=-Wall -Wextra -Werror -g

LINUX=-I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lmlx

MAC=-L/usr/lib -lmlx -framework OpenGL -framework AppKit

RM=rm -f

INC_LIBFT= -L. -lft

FCLEAN_LIB=make -C libft/ fclean

PATH_SRC= ./src/

PATH_HD= -I includes/

SRC = $(PATH_SRC)main.c $(PATH_SRC)ft_julia.c $(PATH_SRC)ft_mandelbrot.c \
	  $(PATH_SRC)ft_controls.c $(PATH_SRC)ft_mouse_hook.c \
	  $(PATH_SRC)ft_draw.c $(PATH_SRC)ft_colours.c $(PATH_SRC)ft_fractal3.c \
	  $(PATH_SRC)ft_redraw.c

OBJ = main.o ft_controls.o ft_mandelbrot.o ft_julia.o ft_mouse_hook.o \
	  ft_colours.o ft_draw.o ft_fractal3.o ft_redraw.o

$(NAME):
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) $(MAC)
	@echo "Compilation was successful!"

all: $(NAME)

x11:
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) $(LINUX)
	@echo "Compilation was successful!"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@make -C libft/ clean
	@echo "Done cleaning!"

fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object & binary files..."
	@make -C libft/ fclean
	@echo "Cleaning binaries..."
	@$(RM) $(NAME)
	@echo "Done cleaning!"

re: fclean all
