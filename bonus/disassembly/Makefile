##
## EPITECH PROJECT, 2021
## B-CPE-201-PAR-2-1-corewar-nicolas.heude
## File description:
## Makefile
##

NAME 		=	disassembly

SRCS 		=	src/disassembly.c \
				src/utility.c \
				src/main.c

HEADER 		=	./include
OBJS 		=	${SRCS:.c=.o}

CC			=	gcc
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CPPFLAGS	+=	-I ${HEADER}

all:		${NAME}


debug: CFLAGS += -g3
debug: re

${NAME}:	${OBJS}
		${CC} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS} *gc*

fclean:		clean
		${RM} ${NAME} unit_tests

re:			fclean all

.PHONY: all lib clean fclean re
