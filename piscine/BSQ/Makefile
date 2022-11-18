CC 		=	 cc

FLAG 	= 	-Wextra -Werror -Wall 

RM 		= 	rm -f

NAME 	= 	bsq

SRC 	= 	main.c \
			srcs/ft_atoi.c srcs/ft_clean_tab.c srcs/ft_find_len_max.c \
			srcs/ft_putstr.c srcs/ft_strdup.c srcs/ft_strlen.c srcs/ft_split.c \
			read/open_file.c read/check_display.c \
			algo/find_treasure.c algo/drink_rhum.c \

OBJ 	= 	${SRC:.c=.o}

HEAD 	= 	includes/

INC		=	${HEAD}ft.h ${HEAD}algo.h ${HEAD}srcs.h ${HEAD}read.h

all: 		${NAME}

.c.o:
			${CC} ${FLAG} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${INC}
			${CC} -o $@ ${OBJ}

clean:		
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re	
