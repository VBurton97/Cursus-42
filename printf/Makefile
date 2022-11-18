######### Name and Folder #########
NAME 	:= libftprintf.a

INC		:=	ft_printf.h

DIR_OBJS := OBJS/

SRC 	:= ft_printf.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putnbr_base.c \
			ft_putstr.c \
			ft_putnbr_adresse_exa.c \
			ft_putnbr_unsigned.c

######### Compileur and various options ########
CC 		:=	 cc

FLAGS 	:= 	-Wextra -Werror -Wall

AR 	:= ar rc

TRI := ranlib

RM 		:= 	rm -rf

########## Rules and dependency ###########
OBJS 	:= 	${SRC:%.c=${DIR_OBJS}%.o}

all: 		${NAME}

${DIR_OBJS}%.o:		%.c ${INC} Makefile
			mkdir -p $(@D)
			${CC} ${FLAGS} -c $< -o $@

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${TRI} ${NAME}

clean:
			${RM} ${DIR_OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
