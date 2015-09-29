# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/29 12:05:06 by emammadz          #+#    #+#              #
#    Updated: 2015/09/29 12:11:02 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = philo

SRCC =	main.c\

SRCO = $(SRCC:%.c=%.o)

FLAG = -Wall -Werror -Wextra

.PHONY: all fast clean fclean

all: philo

%.o: %.c
	@echo -n  $< :
	@gcc -o $@ -c $< $(FLAG)
	@echo

philo: $(SRCO)
	@gcc -o $(EXEC) $(FLAG) $(SRCO)

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm $(EXEC)

re: fclean all
