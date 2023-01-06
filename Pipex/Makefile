######### Name and Folder #########
NAME 	:= pipex

INC		:=	pipex.h

DIR_OBJS := OBJS/

SRC 	:= ft_pipex.c \
			utils.c \
			error.c

PATH_LIBFT	:= libft/

PATH_PRINTF := ft_printf/

######### Compileur and various options ########
CC 		:=	 cc

FLAGS 	:= 	-Wextra -Werror -Wall

RM 		:= 	rm -rf

########## Rules and dependency ###########
OBJS 	:= 	${SRC:%.c=${DIR_OBJS}%.o}

OBJS_B	:= ${SRC_BONUS:%.c=${DIR_OBJS}%.o}

all: 		mklib ${NAME}

${DIR_OBJS}%.o:		%.c ${INC}
			mkdir -p $(@D)
			${CC} ${FLAGS} -c $< -o $@

$(NAME):	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS} ${PATH_LIBFT}libft.a ${PATH_PRINTF}libftprintf.a

bonus :		${OBJS} ${OBJS_B}
			${CC} ${FLAGS} -o ${NAME} ${OBJS} ${OBJS_B} ${PATH_LIBFT}libft.a ${PATH_PRINTF}libftprintf.a

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

.PHONY:		all clean fclean re mklib
