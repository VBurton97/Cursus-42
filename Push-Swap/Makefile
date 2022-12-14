######### Name and Folder #########
NAME 	:= libft.a

INC		:=	libft.h
INCPRF	:= ft_printf.h
INCP	:=	push_swap.h

DIR_OBJS := OBJS/

SRC 	:= ft_atoi.c \
			push_swap.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			swap.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putnbr_adresse_hexa.c \
			ft_putnbr_base.c \
			ft_putnbr_unsigned.c \
			ft_putnbr.c \
			ft_putstr.c

######### Compileur and various options ########
CC 		:=	 cc

FLAGS 	:= 	-Wextra -Werror -Wall

AR 	:= ar rc

TRI := ranlib

RM 		:= 	rm -rf

########## Rules and dependency ###########
OBJS 	:= 	${SRC:%.c=${DIR_OBJS}%.o}

all: 		${NAME}

${DIR_OBJS}%.o:		%.c ${INC} ${INCP} ${INCPRF} Makefile
			mkdir -p $(@D)
			${CC} ${FLAGS} -c $< -o $@

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${TRI} ${NAME}

bonus:		${OBJS} ${OBJS_B}
			${AR} ${NAME} ${OBJS} ${OBJS_B}
			${TRI} ${NAME}

clean:
			${RM} ${DIR_OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re bonus
