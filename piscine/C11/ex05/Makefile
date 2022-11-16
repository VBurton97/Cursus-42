CC 		=	 cc

FLAG 	= 	-Wextra -Werror -Wall 

RM 		= 	rm -f

NAME 	= 	do-op

SRC 	= 	main.c ft_atoi.c ft_putnbr.c ft_strcmp.c operand.c tab_fcts.c ft_putstr.c

OBJ 	= 	${SRC:.c=.o}

INC		=	ft.h

all: 		${NAME}

.c.o:
			${CC} ${FLAG} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ} ${INC}
			${CC} -o $@ ${OBJ}

clean:		
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re	
