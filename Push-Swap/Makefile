######### Name and Folder #########
NAME 	:= push_swap

INC	:=	push_swap.h

PATH_LIBFT := libft/

PATH_PRINTF := ft_printf/

DIR_OBJS := OBJS/

SRC 	:=	push_swap.c \
			push_swap_bis.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			swap.c \
			utils.c \
			utils_2.c


######### Compileur and various options ########
CC 		:=	 cc

FLAGS 	:= 	-Wextra -Werror -Wall

RM 		:= 	rm -rf

########## Rules and dependency ###########
OBJS 	:= 	${SRC:%.c=${DIR_OBJS}%.o}

all: 		mklib ${NAME}

${DIR_OBJS}%.o:		%.c ${INC}
			mkdir -p $(@D)
			${CC}  -c $< -o $@

$(NAME):	${OBJS}
			${CC}  -o ${NAME} ${OBJS} ${PATH_LIBFT}libft.a ${PATH_PRINTF}libftprintf.a

mklib:
			make -j -C ${PATH_LIBFT}
			make -j -C ${PATH_PRINTF}

clean:
			${RM} ${DIR_OBJS}
			make clean -C ${PATH_LIBFT}
			make clean -C ${PATH_PRINTF}

fclean:		clean
			${RM} ${NAME}
			make fclean -C ${PATH_LIBFT}
			make fclean -C ${PATH_PRINTF}

re: 		fclean all

.PHONY:		all clean fclean re bonus
