
NAME	=	mini_serv

SRC		=	mini_serv.c

OBJ		=	${SRC:.c=.o}

CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

.PHONY	:	all clean fclean re

all		:	${NAME}

${NAME}	:	${OBJ}
			@${CC} ${FLAGS} ${OBJ} -o ${NAME}
			@printf "File '${NAME}' is created and run! â \n"
			./${NAME} 6000

clean	:
			@${RM} ${OBJ}
			@printf "File '${OBJ}' is deleted! đī¸ \n"

fclean	:	clean
			@${RM} ${NAME}
			@printf "File '${NAME}' is deleted! đī¸ \nī¸ī¸"

re		:	fclean all
