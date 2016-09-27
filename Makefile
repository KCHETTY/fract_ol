# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antricht <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/27 11:14:44 by antricht          #+#    #+#              #
#    Updated: 2016/09/27 11:29:58 by antricht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c

FLAGS = -lmlx -framework OpenGL -framework Appkit

$(NAME):
	@echo Compiling...
	@gcc -o $(NAME) $(SRCS) $(FLAGS)
	@echo Compiled!

clean:
	@rm $(NAME)
	@echo Application removed!

flcean: clean

re: clean $(NAME)
