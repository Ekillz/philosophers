# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/29 12:05:06 by emammadz          #+#    #+#              #
#    Updated: 2015/10/13 17:23:35 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = philo

SRCC =	main.c\
		loop.c\
		ft_mlx.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_itoa.c\
		ft_memdel.c\
		ft_freetab.c\
		draw.c\
		draw2.c\

SRCO = $(SRCC:%.c=%.o)

FLAG = -Wall -Werror -Wextra -ggdb

LIB = -framework OpenGL -framework AppKit -L mlx

.PHONY: all fast clean fclean

all: philo

%.o: %.c
	@echo -n  $< :
	@gcc -o $@ -c $< $(FLAG) -pthread
	@echo

philo: $(SRCO)
	@make -C mlx
	@gcc -o $(EXEC) $(FLAG) $(SRCO) mlx/libmlx.a $(LIB)

clean:
	@make clean -C mlx
	@rm -f $(SRCO)

fclean: clean
	@rm $(EXEC)

re: fclean all
	@make re -C mlx
