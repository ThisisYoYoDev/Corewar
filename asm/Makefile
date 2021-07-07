##
## EPITECH PROJECT, 2021
## B-CPE-201-PAR-2-1-corewar-nicolas.heude
## File description:
## Makefile
##

NAME 		=	asm

SRCS 		=	src/main.c											\
				src/instructions/instructions_checking.c			\
				src/instructions/instructions_add.c					\
				src/utils/utils_corewar_free_part_two.c				\
				src/utils/utils_corewar_getline.c					\
				src/utils/utils_corewar_line_test.c					\
				src/utils/utils_corewar_free.c						\
				src/utils/utils_corewar_init.c						\
				src/get/get_code.c									\
				src/get/get_parameter.c								\
				src/labels/labels_add.c								\
				src/labels/labels_check.c							\
				src/write/write_header.c							\
				src/write/write_label.c								\
				src/instructions/instruction_check_codebyte.c		\

SRC_TESTS 	=	src/instructions/instructions_checking.c			\
				src/instructions/instructions_add.c					\
				src/utils/utils_corewar_free_part_two.c				\
				src/utils/utils_corewar_getline.c					\
				src/utils/utils_corewar_line_test.c					\
				src/utils/utils_corewar_free.c						\
				src/utils/utils_corewar_init.c						\
				src/get/get_code.c									\
				src/get/get_parameter.c								\
				src/labels/labels_add.c								\
				src/labels/labels_check.c							\
				src/write/write_header.c							\
				src/write/write_label.c								\
				src/instructions/instruction_check_codebyte.c		\
				../tests/asm/tests_main.c							\
				../tests/asm/test_exec.c							\

HEADER_LIB 	=	./lib/my/include
HEADER 		=	./include
LIB 		=	./lib/my
OBJS 		=	${SRCS:.c=.o}

CC			=	gcc
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CPPFLAGS	+=	-I ${HEADER}
CPPFLAGS	+=	-I ${HEADER_LIB}
LDFLAGS		=	-L ${LIB} -lmy

all:		lib ${NAME}

lib:
		make -C ./lib/my

debug: CFLAGS += -g3
debug: re

${NAME}:	${OBJS}
		${CC} ${OBJS} ${LDFLAGS} -o ${NAME}

clean:
		make clean -C ./lib/my
		${RM} ${OBJS} *gc* *.cor

fclean:		clean
		make fclean -C ./lib/my
		${RM} ${NAME} unit_tests

re:			fclean all

tests_cover :	tests_run
	gcc	../bonus/display_coverage.c
	gcovr --exclude ../tests/ > out_cover
	./a.out out_cover;
	gcovr --exclude ../tests/ --branch > out_cover
	./a.out out_cover;
	make clean > out_cover
	rm -f a.out
	rm -f unit_tests
	rm -f out_cover

tests_run:		re
				${CC} -o unit_tests ${SRC_TESTS} ${LDFLAGS} ${CFLAGS} ${CPPFLAGS} --coverage -lcriterion
				./unit_tests
				rm -f *.cor

coverage: 		tests_run
				gcovr --exclude tests/

branches: 		tests_run
				gcovr --exclude tests/ --branches

.PHONY: all lib clean fclean re tests_run coverage branches
