# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vburton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 11:35:22 by vburton           #+#    #+#              #
#    Updated: 2022/09/18 22:01:22 by vburton          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/

SRCS = ${SRC}ft_putchar.c ${SRC}ft_swap.c ${SRC}ft_putstr.c ${SRC}ft_strlen.c ${SRC}ft_strcmp.c

OBJS = ${SRCS:.c=.o}

HEAD = includes  

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

RM = rm -f

AR = ar rc

RAN = ranlib

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}


all: 		$(NAME)

$(NAME) :	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RAN} ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME)

re: fclean all 
